#define MAXNUM 10001
template <typename T>
class max_heap{
    int n;
    T heap[MAXNUM];
public: 
    max_heap():n(0){}
    void push(T a){         //自底向上，为a寻找一个合适的位置插入
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
    void pop(){         //弹出顶部元素，自顶向下，为最后一个节点找到合适的地方插入
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
