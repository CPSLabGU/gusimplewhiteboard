    import XCTest
    @testable import cwhiteboard

    final class cwhiteboardTests: XCTestCase {
        func testWBD() {
            let wbd = gu_simple_whiteboard_descriptor()
            XCTAssertEqual(wbd.fd, 0)
        }
    }
