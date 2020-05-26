#define MAXNUM 10001
template <typename T>
class max_heap{
    int n;
    T heap[MAXNUM];
public: 
    max_heap():n(0){}
    void push(T a){
        int pos = ++n, fatherpos = n >> 1;
        while(fatherpos){
            if(a > heap[fatherpos]){
            heap[pos] = heap[fatherpos];
            pos = fatherpos;
            fatherpos>>=1;
            }else break;
        }
        heap[pos] = a;
    }
    void pop(){
        T a = heap[n--];
        int root = 1, kid = 2;
        while(kid <= n) {
            if(kid < n && heap[kid|1] > heap[kid]) kid|=1; //这里如果kid=n的话说明没有右节点，就不需要做左右节点大小的判断了
            if(a < heap[kid]){
                heap[root] = heap[kid];
                root = kid;
                kid <<=1;
            }else break;
        }
        heap[root] = a;
    }    
    T top(){
        return heap[1];
    }
    T* getbyid(int id){
        return &heap[id];
    }
};
