    import XCTest
    @testable import cwhiteboard

    final class cwhiteboardTests: XCTestCase {
        func testExample() {
            let foo = gsw_whiteboard_s()
            XCTAssertEqual(foo.num_messages, 0)
        }
    }
