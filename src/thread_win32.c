#include "thread.h"

#include <stdlib.h>
#include <windows.h>

typedef void *(*ThreadFunc)(void *);

typedef struct Thread {
    HANDLE handle;
} Thread;

Thread *
ThreadAlloc(MemoryArena *arena) {
    return ArenaPushStruct(arena, Thread);
}

typedef struct ThreadData {
    ThreadFunc func;
    void      *data;
} ThreadData;

DWORD
ThreadFuncWrapper(void *user_data) {
    ThreadData *thread_data = (ThreadData *)user_data;

    thread_data->func(thread_data->data);

    free(thread_data);
    return 0;
}

void
ThreadCreate(Thread *thread, ThreadFunc thread_func, void *data) {
    ThreadData *thread_data = malloc(sizeof(ThreadData));
    thread_data->func = thread_func;
    thread_data->data = data;

    thread->handle =
        CreateThread(NULL, 0, ThreadFuncWrapper, thread_data, 0, NULL);
}

void
ThreadJoin(Thread *thread) {
    if (thread->handle) {
        WaitForSingleObject(thread->handle, INFINITE);
    }
}
