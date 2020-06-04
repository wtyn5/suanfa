#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int n;//Բ�ĸ���
double len=1000000,x[MAXN],r[MAXN];//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ��������飬ÿ��Բ�뾶����
double bestv[MAXN];//��СԲ���еİ뾶˳��
double center(int t){//�õ���t��Բ��Բ�ĺ�����
    double tmp = 0;
    for (int i = 1; i < t; ++i) {//�����t��Բ��ǰ��(���Ϊ1~t-1)������Բ����ʱ�ľ��룬��������
        double xvalue = x[i] + 2.0 * sqrt(r[i]*r[t]);//�����t��Բ���i��Բ����ʱ�ľ���
        if (xvalue > tmp) {//���ľ������Բ������
            tmp = xvalue;
        }
    }
    return tmp;
}
void compute(){//���㵱ǰԲ���г���
    double low=0,high=0;
    for (int i = 1; i <= n; ++i) {//Ѱ������������Ҷ˵ľ���
        if (x[i] - r[i] < low) {
            low = x[i] - r[i];
        }
        if (x[i] + r[i] > high) {
            high = x[i] + r[i];
        }
    }
    if (high - low < len) {
        len = high - low;//��������ֵ
        for (int i = 1; i <= n; ++i) {//����һ������ ��¼����Բ���е�˳�� 
            bestv[i] = r[i];
        }
    }
}
void Backtrack(int t){
    if (t > n)
        compute();
    else{
        for (int i = t; i <= n; ++i) {//ȷ��ȫ���У�һ��ʼ��˳���ʱ��û��������һ�����к󣬻���ʱi��t��ͬ
            swap(r[t], r[i]);
            double centerx = center(t);//�����t��Բ�ĺ�����
            if (centerx + r[1] + r[t] < len) {//��֦
                x[t] = centerx;//ȷ���˼����t��Բ��Բ���г���
                Backtrack(t + 1);//������һ��Բ
            }
            swap(r[t], r[i]);//���ݣ���ǰ��ȫ���н�����ԭ���ٽ��ŴӸ�ǰһ��Ԫ�ؿ�ʼ����
        }
    }
}
int main()
{
    cout << "Բ�ĸ��� n��";
    cin >> n;
    cout << "ÿ��Բ�İ뾶�ֱ�Ϊ��";
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    Backtrack(1);
    cout << "��СԲ���г���Ϊ��" << len <<endl;
    cout << "����Բ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��";
    for (int i = 1; i <= n; ++i) {
        cout << bestv[i] << " ";
    }
	cout << endl;
    return 0;
}

