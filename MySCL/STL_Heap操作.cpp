#include <iostream>
#include <algorithm> // make_heap(), pop_heap(), push_heap()
#include <vector>
using namespace std;

void printVector(vector<int> &num)
{
    for(int i = 0; i < num.size(); i++)
        cout<<num[i]<<" ";
    cout<<endl;
}
int main()
{
    // init
    int arr[] = {5,1,6,9,4,3};
    vector<int> num(arr,arr+6);
    printVector(num);

    // build
    make_heap(num.begin(),num.end());
    printVector(num); // 9 5 6 1 4 3 默认大顶堆

    // get the biggest number
    // 从vector的角度来取得
    cout<<num[0]<<endl; // 9
    // or num.front();
    cout<<num.front()<<endl; // 9

    // delete 堆顶，即最大的元素
    // 返回值为 void 
    // 将堆顶的元素放到最后一个位置上
    // 弹出一个元素后，剩下的又重建了 heap，仍保持heap的性质
    pop_heap(num.begin(),num.end());
    printVector(num); // 6 5 3 1 4 9
    // vector 删除末尾元素
    num.pop_back();
    printVector(num);

    num.push_back(7); //首先在vector上扩容，增加一个元素到尾部
    printVector(num); // 6 5 3 1 4 7 
    push_heap(num.begin(),num.end());  // 指定区间的最后一个元素加入堆中并使整个区间成为一个新的堆。注意前提是最后一个元素除外的所有元素已经构成一个堆。
    printVector(num);  // 7 5 6 1 4 3

    // 判断是否为堆
    bool ret = is_heap(num.begin(),num.end());
    cout<<ret<<endl;
    num.push_back(9);
    printVector(num);  // 7 5 6 1 4 3 9
    cout<< is_heap(num.begin(),num.end()) <<endl;
    push_heap(num.begin(),num.end());
    printVector(num); // 9 5 7 1 4 3 6

    sort_heap(num.begin(),num.end());
    printVector(num); // 1 3 4 5 6 7 9
}
 

// 小顶堆
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class greater_class{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    // init
    int arr[] = {5,1,6,9,4,3};
    vector<int> num(arr,arr+6);
    printVector(num);

    make_heap(num.begin(), num.end(), greater_class());
    printVector(num); // 1 4 3 9 5 6 

    num.push_back(2);
    printVector(num); // 1 4 3 9 5 6 2
    push_heap(num.begin(),num.end(),greater_class());
    printVector(num); // 1 4 2 9 5 6 3 

    while (num.size())
    {
        pop_heap(num.begin(),num.end(),greater_class());
        long min = num.back();
        num.pop_back();  
        cout << min << std::endl;
    } // 1 2 3 4 5 6 9
}