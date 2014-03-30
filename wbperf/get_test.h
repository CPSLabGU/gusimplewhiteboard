//
//  get_test.h
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 ICT. All rights reserved.
//

#ifndef __gusimplewhiteboard__get_test__
#define __gusimplewhiteboard__get_test__

#include <guwhiteboardtypelist_generated.h>
#include <guwhiteboardgetter.h>
#include "perftest.h"

class get_test: public perftest
{
    PROPERTY(guWhiteboard::SpeechOutput_t, bool_value)

public:
    get_test(): perftest(), _bool_value() {}
    virtual void run_test(long iterations);
    virtual void print(long iterations) { std::cout << "Get:  "; perftest::print(iterations); }
};


#endif /* defined(__gusimplewhiteboard__get_test__) */
