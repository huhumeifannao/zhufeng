1.#include<iostream>//ͷ�ļ������������ 
using namespace std;
int main()
{
	cout<<"Hello World!"<<endl;
	return 0;
} 
2.c++���� 
int number=1;
char character='a';
bool boolean=true;//�����������ͣ�0��1 
char *cString="Hello";
string cppString="World"; //�����ַ������� 
struct node 
{
  int a,b;
  node* next;
}
node*next;//c++ʹ�ýṹ������ʱ������Ҫ��ǰ���һ��struct,ֱ��ʹ�ýṹ������

#include<iostream>
using namespace std;
struct node 
{
	int a,b;
	st(int x,int y)//���캯��,�ṹ��Ĺ��캯����ṹ��ͬ�� 
	{
		a=x;
		b=y; 
	}
};
int main()
{
	st newst=(1,2);//�ṹ��Ĺ��캯���ڴ�����Ӧ�ṹ���ʱ������Զ����� 
	cout<<newst.a<<newst.b;
	return 0;
}
3��c++�������
�ԣ�
//����һ���ַ���
getline(cin,�ַ���������);
cin.getline(�ַ�����������1000);//1000Ϊ������ַ�������
//ʹ��getline()֮ǰ��������������������ô��getline()ǰдһ��getchar()���̵���һ����������������Ļ��з�
4.//��̬�ڴ���� 
int *number=new int;//c++�� 
int *arr=new int[100];//c++�� 
int *carr=(int*)malloc(100*sizeof(int));//c��������̬�����ڴ�
//c++����new����̬�����ڴ棬newд��������Ӽ���һ�㡣
//����c++��֧�ֱ䳤���飬��new int[len],lenһ��Ҫ��һ������
���룺
#include<iostream>
using namespace std;
struct node
{
	int value;
	node*next;
	node(int x)
	{
		value=x;
	}
 } ;
 node *head;
 int main()
{
	head=new node(1);//��head��̬����headָ���node�ռ� 
	head->next=new node(2);
	node* second=head->next;
	cout<<"��һ��ֵΪ��"<<head->value<<endl;
	cout<<"�ڶ���ֵΪ��"<<second->value<<endl;
	cout<<"������ֵΪ��"<<head->next->value<<endl;
}
//��һ��ֵΪ1���ڶ���ֵΪ2��������ֵΪ3 
//��ƽʱ�ж�̬�ڴ�ķ���һ�������½�һ���ṹ���ϣ����ҿ��Բ����ͷ��ڴ�
5.�������ͣ�
#include<iostream>
using namespace std;
void swap(int &a,int &b)//�βε�ǰ���һ��&����ʾ�Դ���ı�����һ������ 
// ��swap�е�a����mian �д����a����һ�������ռ䣬����������Ч���ǿ��԰�swap�еı�����a����main�����еı���a��ֱ��ʹ�� 
{
	int temp=b;
	b=a;
	a=temp;
 } 
int main()
{
	int a=1;
	int b=1;
	swap(a,b);
	cout<<"a= "<<a<<"b= "<<b<<endl;
	return 0;
}
6��������
#include<iostream>
using namespace std;
int sum(int a)
{
	cout<<"��ֵ"<<endl;
	return "2"; 
}
double sum(double a)
{
	cout<<"��ֵ"<<endl;
	return "6.9";
}
int sum(int a,int b)
{
	cout<<"��ֵ"<<endl;
	return 6;
}
int main()
{
	int a=1;
	int b=1;
	double c=1.1;
	cout<<sum(a)<<endl;
	cout<<sum(c)<<endl;
	cout<<sum(a,b)<<endl;
	return 0;
}
������ȱʡֵ:���ȱ�Ļ�ֱ�Ӿ���ԭ���ĸ��Oֵ����ʡ�� 
#include<iostream>
using namespace std;
int sum(int a,int b=0)
{
	cout<<sum(int a,int b)<<endl;
	return a+b;
}
int main()
{
	int a=1;
	int b=2;
	cout<<sum(a)<<endl;//���Ϊ1 
	cout<<sum(a,b)<<endl;//���Ϊ3 
	return 0;
}
ע�⣺�����������ң�һ������ȱʡֵ�����󣬺���Ĳ����������ȱʡֵ 
����ʾ����
int main(int a,int b=0,int c)
{
	cout<<sum(a+b)<<endl;
	return a+b;
}
�˺����Ǵ���ġ�
//������ȱʡֵ����ĵ�������
#include<iostream>
using namespace std;
int sum(int a,int b=0)
{
	cout<<sum(a+b)<<endl;
	return a+b;
 } 
 int main()
 {
 	int a=1;
 	int b=2;
 	cout<<sum(a)<<endl;
 	return 0;
 }
//������int sum(int a,int b=0),����int sum(int a)ʱ���ᷢ�����壬���������޷��ж�����ʲô���� 
7�����������
//�������������������ؽṹ����������ʹ�ṹ��Ҳӵ�кͱ�׼��������һ���������
#include<iostream>
using namespace std;
struct student
{
	int A_score;
	int B_score;
	student(int a,int b):A_score(a),B_score(b)
	{
		
	} //Ҳ����ֱ��ʹ��student���캯��,ǰ����ʵ�� 
	bool operator<(const student b)
	{
		return this->A_score<b.A_score;
	}
} 
//��Ϊ����һ��������ʵ��
#include<iostream>
using namespace std;
struct student
{
	int A_score;
	int B_score;
	student(int a,int b):A_score(a),B_score(b){}
	bool operator<(const student b)
	{
		if(this->A_score!=b.A_score)
		return this->A_score<b.A_score;
		else
		return this->B_score<b.B_score;
	}
	//�ȿ��Ƚ�ǰ��a���� 
} 
int main()
{
	student student1(100,90);
	student student2(100,89);
	student student3(99,100);
	cout<<(student1<student2)<<endl;//0
	cout<<(student1<student3)<<endl;//0
	cout<<(student3<student2)<<endl;//1
	return 0;
}








��

