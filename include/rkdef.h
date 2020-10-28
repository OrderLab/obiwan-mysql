#ifndef __RKDEF_H__
#define __RKDEF_H__

#include <vector>
#include <chrono>
#include <atomic>
#include <pthread.h>

using namespace std::chrono;

enum RecType { DOCMD, DOCMD_BGN, DOCMD_END, DLCK, DLCK_BGN, DLCK_END };

struct Rec {
    RecType rec_type;
    pthread_t tid;  // assume the pointer are different
    long long duration;
};

#define RKLOGMAX 1000000
extern std::atomic_size_t all_log_count;
extern std::vector<Rec> all_log;

inline void put_log(RecType r, pthread_t t, long long d) {
    size_t count = all_log_count++;
    if (all_log_count >= RKLOGMAX) {
        all_log[count].rec_type = r;
        all_log[count].tid = t;
        all_log[count].duration = d;
    }
}

#endif /* __RKDEF_H__ */
