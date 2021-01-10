#include <queue>
#include <iostream>
using namespace std;
priority_queue<int>pq;
priority_queue<int>ao;
int main()
{
    int n;
    scanf_s("%d", &n);
    while (n--) {
        int x;
        scanf_s("%d", &x);
        pq.push(x);
        ao.push(x);
        //cout << pq.size() << endl;

       
            int y = pq.size() / 2;
            for (int i = 0; i < y; i++) {
                pq.pop();
            }
            printf("중간값 : %d\n", pq.top());
        
       
        pq = ao;
        

        //printf("%d\n", pq.top());


    }

}

