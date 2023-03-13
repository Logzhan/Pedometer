#include <iostream>
#include <vector>

template <typename T, int N>
class Buffer {
public:
    Buffer() :
        data(N), sum(0), count(0), front(0), rear(0) {
    }

    void insert(T x) {
        if (count == N) {
            sum -= data[front];
            front = (front + 1) % N;
            count--;
        }
        data[rear] = x;
        sum += x;
        count++;
        rear = (rear + 1) % N;
    }

    float meanFast() {
        if (count == 0) {
            return 0.0f;
        }
        return (float)sum / count;
    }

private:
    std::vector<T> data;
    double sum;
    size_t count;
    size_t front;
    size_t rear;
};

int main() {
    Buffer<int, 4> buff;
    buff.insert(10);
    buff.insert(20);
    buff.insert(30);
    buff.insert(40);
    buff.insert(50);
    std::cout << "Buffer mean = " << buff.meanFast() << std::endl;
    system("pause");
    return 0;
}