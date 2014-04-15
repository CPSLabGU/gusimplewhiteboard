//
//  perftest.h
//  gusimplewhiteboard
//
//  Created by Rene Hexel on 30/03/2014.
//  Copyright (c) 2014 Rene Hexel. All rights reserved.
//

#ifndef __gusimplewhiteboard__perftest__
#define __gusimplewhiteboard__perftest__

#include <cstdio>
#include <gu_util.h>

//#define PERFTEST_DEFAULT_ITERATIONS 1000000000L
#define PERFTEST_DEFAULT_ITERATIONS 100000000L

class perftest
{
    PROPERTY(long long, start_time)
    PROPERTY(long long, end_time)

public:
    perftest() {}
    virtual void run(long iterations = PERFTEST_DEFAULT_ITERATIONS) { setup(iterations); run_test(iterations); finish(iterations); print(iterations); }
    virtual void setup(long /* iterations */) { run_test(256); set_start_time(get_utime()); }
    virtual void run_test(long /* iterations */) {}
    virtual void finish(long /* iterations */) { set_end_time(get_utime()); }
    virtual void print(long iterations) { double nsec = static_cast<double>(end_time()-start_time())/1000000.0; printf("%3.5g seconds for %ld iterations (%9ld iterations/second)\n", nsec, iterations, static_cast<long>(iterations/nsec)); }
    virtual ~perftest() {}
};

#endif /* defined(__gusimplewhiteboard__perftest__) */
