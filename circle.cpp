#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int n;//圆的个数
double len=1000000,x[MAXN],r[MAXN];//分别为最小圆排列长度，每个圆心横坐标数组，每个圆半径数组
double bestv[MAXN];//最小圆排列的半径顺序
double center(int t){//得到第t个圆的圆心横坐标
    double tmp = 0;
    for (int i = 1; i < t; ++i) {//计算第t个圆与前面(序号为1~t-1)已排列圆相切时的距离，求最大距离
        double xvalue = x[i] + 2.0 * sqrt(r[i]*r[t]);//计算第t个圆与第i个圆相切时的距离
        if (xvalue > tmp) {//最大的距离就是圆心坐标
            tmp = xvalue;
        }
    }
    return tmp;
}
void compute(){//计算当前圆排列长度
    double low=0,high=0;
    for (int i = 1; i <= n; ++i) {//寻找最左端与最右端的距离
        if (x[i] - r[i] < low) {
            low = x[i] - r[i];
        }
        if (x[i] + r[i] > high) {
            high = x[i] + r[i];
        }
    }
    if (high - low < len) {
        len = high - low;//更新最优值
        for (int i = 1; i <= n; ++i) {//设置一个数组 记录最优圆排列的顺序 
            bestv[i] = r[i];
        }
    }
}
void Backtrack(int t){
    if (t > n)
        compute();
    else{
        for (int i = t; i <= n; ++i) {//确保全排列：一开始按顺序的时候没交换，第一次排列后，回溯时i与t不同
            swap(r[t], r[i]);
            double centerx = center(t);//计算第t个圆的横坐标
            if (centerx + r[1] + r[t] < len) {//剪枝
                x[t] = centerx;//确定了加入第t个圆的圆排列长度
                Backtrack(t + 1);//搜索下一个圆
            }
            swap(r[t], r[i]);//回溯，将前面全排列结束后复原，再接着从更前一个元素开始排列
        }
    }
}
int main()
{
    cout << "圆的个数 n：";
    cin >> n;
    cout << "每个圆的半径分别为：";
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    Backtrack(1);
    cout << "最小圆排列长度为：" << len <<endl;
    cout << "最优圆排列的顺序对应的半径分别为：";
    for (int i = 1; i <= n; ++i) {
        cout << bestv[i] << " ";
    }
	cout << endl;
    return 0;
}

