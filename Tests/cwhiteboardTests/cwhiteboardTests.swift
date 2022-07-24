import XCTest
@testable import cwhiteboard

private let testWBName = "test-cwhiteboard"

final class cwhiteboardTests: XCTestCase {
    var wbd: UnsafeMutablePointer<gu_simple_whiteboard_descriptor>! = gsw_new_simple_whiteboard(testWBName)

    deinit {
        gsw_free_whiteboard(wbd)
        try? FileManager.default.removeItem(atPath: "/tmp/" + testWBName)
    }

    /// Test whiteboard invariants
    func testWB() {
        guard let wb = wbd.pointee.wb else {
            XCTAssertNotNil(wbd.pointee.wb)
            return
        }
        XCTAssertEqual(wb.pointee.magic, 0xfeeda11deadbeef6)
        XCTAssertEqual(wb.pointee.version, 2207)
        XCTAssertNotEqual(wbd.pointee.fd, 0)
        XCTAssertEqual(wb.pointee.indexes.0, 0)
        XCTAssertEqual(wb.pointee.event_counters.0, 0)
    }

    /// Test posting and fetching message at index 1
    func testPost() {
        guard let wb = wbd.pointee.wb else {
            XCTAssertNotNil(wbd.pointee.wb)
            return
        }
        let postValue: UInt64 = 0xfeed
        let i = wb.pointee.indexes.1
        let e = wb.pointee.event_counters.1
        guard let next = gsw_next_message(wb, 1) else {
            XCTFail() ; return
        }
        next.pointee.u64 = postValue
        wb.pointee.indexes.1 = (wb.pointee.indexes.1 + 1) % UInt8(GU_SIMPLE_WHITEBOARD_GENERATIONS)
        wb.pointee.event_counters.1 &+= 1
        guard let current = gsw_current_message(wb, 1) else {
            XCTFail() ; return
        }
        XCTAssertEqual(current, next)
        XCTAssertEqual(current.pointee.u64, postValue)
        XCTAssertEqual(wb.pointee.indexes.1, (i + 1) % UInt8(GU_SIMPLE_WHITEBOARD_GENERATIONS))
        XCTAssertEqual(wb.pointee.event_counters.1, e &+ 1)
    }
}
