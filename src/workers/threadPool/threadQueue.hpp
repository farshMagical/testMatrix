#pragma once

#include <deque>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadQueue{
public:
    void Put(T item){
        std::lock_guard<std::mutex> lg(mutex);
        queue.push_back(std::move(item));
        waitItem.notify_one();
    }

    T Take(){
        std::unique_lock ul(mutex);
        while(queue.empty()){
            waitItem.wait(ul);
        }
        T front = std::move(queue.front());
        queue.pop_front();
        return front;
    }
        
private:
    std::deque<T> queue;
    std::mutex mutex;
    std::condition_variable waitItem;
};
