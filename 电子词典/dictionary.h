#ifndef DICTIONARY_H_
#define DICTIONARY_H_


#define Max 10000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

void menu();


/*-----------find2--------*/
typedef struct indexHead{
  char name[200];  //物质名
  int offset;     //偏移量
  struct indexHead *left;   //左子树
  struct indexHead *right;
  int heigh;
}node;
/*----------全局变量-------------------*/

char filename[40];

 
/*功能：遍历二叉树，将树中信息输出；输入：根节点*/
void printfTree2(node *root);
/*功能：获取ALV树节点的高度；输入：根节点*/
int getHight(node* A);
/*功能：左旋；输入：根节点*/
void leftRotate(node**A);
/*功能：右旋；输入：根节点*/
void rightRotate(node**A);
/*功能：右左旋；输入：根节点*/
void rightLeftRotate(node**A); 
/*功能：左右旋；输入：根节点*/
void leftRightRotate(node**A);  
/*功能：将结构体插入AVL树中；输入：根节点地址*/
void insertNode(node **root,node *newnode);
/*功能：根据名字查找，若查找不到则打印无法查找，若查找到则读取其偏移量，交付给findOffset()函数；输入：根节点地址，新的结构体，判断标志*/ 
void findTree(node *root,char *name,int* flag);


/*-----------find2---------*/
/*建立二进制索引文件index.dat*/
void creatIndex();
/*计算索引文件中开始存放正文的地方*/
int locatecontent();
/*读取二进制索引文件，生成平衡树，方便查找 */
void indexTree();
/*计算hazaTest.txt文件中共几个物质 */
int count();

/**/
void find1();
void find2();



/*-----------find1----------------*/
/*链表的内容*/
struct list{
		char name[Max];          //记录有害物质名字
        char info[Max];			 // 记录有害物质信息
        struct list *next;		 //指向下一个内容
};
/*功能创建树，传入根节点以及*/
void create_list(struct list *node,struct list *temp);
/*功能：根据名字查找内容--输入根节点和查找名字*/
void find_list(struct list *node,char *findname);

/*-----------find1||find2------------------*/

/*调用./app -find1 -f yyy.txt*/
void addFind1();

/*传入查询名字进行查询名字*/
/*-功能调用查找提供文件如果输入 exit 退出系统-传入要查找的名字*/
void findf(char *findname);
/*功能：根据名字查找内容--输入根节点和查找名字*/
void find_list1(struct list *node,char *findname);
/*功能创建树，传入根节点以及*/
void create_list1(struct list *node);
/*如果该文件用户查找不到，新文件也查找不到，用户就输入进去*/
void insert(char *findname);

/*旧文件查找*/
void find_list2(struct list *node,char *findname);

/*find2 找不到就到二进制文件查找*/
void addFind2();

#endif // FIND1_H