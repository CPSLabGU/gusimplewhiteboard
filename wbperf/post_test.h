//
//  post_test.h
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//

#ifndef __gusimplewhiteboard__post_test__
#define __gusimplewhiteboard__post_test__

#include <guwhiteboardtypelist_generated.h>
#include <guwhiteboardposter.h>
#include "perftest.h"

class post_test: public perftest
{
    PROPERTY(guWhiteboard::SpeechOutput_t, bool_value)
public:
    post_test(): perftest(), _bool_value() {}
    virtual void run_test(long iterations);
    virtual void print(long iterations) { std::cout << "Post: "; perftest::print(iterations); }
};


#endif /* defined(__gusimplewhiteboard__post_test__) */
