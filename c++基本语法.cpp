1.#include<iostream>//头文件，输入输出流 
using namespace std;
int main()
{
	cout<<"Hello World!"<<endl;
	return 0;
} 
2.c++定义 
int number=1;
char character='a';
bool boolean=true;//新增布尔类型，0或1 
char *cString="Hello";
string cppString="World"; //新增字符串类型 
struct node 
{
  int a,b;
  node* next;
}
node*next;//c++使用结构体类型时，不需要在前面加一个struct,直接使用结构体名字

#include<iostream>
using namespace std;
struct node 
{
	int a,b;
	st(int x,int y)//构造函数,结构体的构造函数与结构体同名 
	{
		a=x;
		b=y; 
	}
};
int main()
{
	st newst=(1,2);//结构体的构造函数在创建对应结构体的时候可以自动调用 
	cout<<newst.a<<newst.b;
	return 0;
}
3、c++输入输出
略；
//输入一行字符串
getline(cin,字符串变量名);
cin.getline(字符串变量名，1000);//1000为读入的字符串上限
//使用getline()之前如果有其他输入操作，那么在getline()前写一个getchar()来吞掉上一步输入操作留下来的换行符
4.//动态内存分配 
int *number=new int;//c++中 
int *arr=new int[100];//c++中 
int *carr=(int*)malloc(100*sizeof(int));//c中用来动态开辟内存
//c++中用new来动态开辟内存，new写起来会更加简明一点。
//由于c++不支持变长数组，即new int[len],len一定要是一个常量
代码：
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
	head=new node(1);//用head动态开辟head指向的node空间 
	head->next=new node(2);
	node* second=head->next;
	cout<<"第一个值为："<<head->value<<endl;
	cout<<"第二个值为："<<second->value<<endl;
	cout<<"第三个值为："<<head->next->value<<endl;
}
//第一个值为1，第二个值为2，第三个值为3 
//在平时中动态内存的分配一般用于新建一个结构体上，并且可以不用释放内存
5.引用类型：
#include<iostream>
using namespace std;
void swap(int &a,int &b)//形参的前面加一个&，表示对传入的变量做一个引用 
// 在swap中的a的与mian 中传入的a公用一个变量空间，这样产生的效果是可以把swap中的变量的a当做main函数中的变量a来直接使用 
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
6函数重载
#include<iostream>
using namespace std;
int sum(int a)
{
	cout<<"数值"<<endl;
	return "2"; 
}
double sum(double a)
{
	cout<<"数值"<<endl;
	return "6.9";
}
int sum(int a,int b)
{
	cout<<"数值"<<endl;
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
函数的缺省值:如果缺的话直接就是原来的给扥值，很省事 
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
	cout<<sum(a)<<endl;//结果为1 
	cout<<sum(a,b)<<endl;//结果为3 
	return 0;
}
注意：参数从左往右，一旦出现缺省值参数后，后面的参数必须带有缺省值 
错误示范：
int main(int a,int b=0,int c)
{
	cout<<sum(a+b)<<endl;
	return a+b;
}
此函数是错误的。
//函数的缺省值引起的调用歧义
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
//当既有int sum(int a,int b=0),又有int sum(int a)时，会发生歧义，编译器将无法判定调用什么函数 
7、运算符重载
//重载运算往往用于重载结构体的运算符，使结构体也拥有和标准数据类型一样的运算符
#include<iostream>
using namespace std;
struct student
{
	int A_score;
	int B_score;
	student(int a,int b):A_score(a),B_score(b)
	{
		
	} //也可以直接使用student构造函数,前面有实例 
	bool operator<(const student b)
	{
		return this->A_score<b.A_score;
	}
} 
//更为复杂一点的运算符实例
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
	//先看比较前面a部分 
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








、

