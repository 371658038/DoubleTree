 #include<iostream>
using namespace std;
#include<stack>
#include<queue>

typedef struct BiNode
{
	char data;
	struct BiNode *lchild,*rchild;
}*BiTree,BiNode;


void Create(BiTree &T)//中序遍历创建一个二叉树 
{
	char ch;
//	cout << ">:";
	cin>>ch;
	if(ch=='#')
	{
		T=NULL;
	}
	else
	{
		T=new BiNode;
		T->data=ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}
void L_Order_Trave(BiTree &T)
{
	BiNode* p = new BiNode;
	BiNode* q = new BiNode;
	p = T;
	stack<BiNode*> S;
	while(p||!S.empty())
	{
		if(p)
		{
			cout<<p->data;
			S.push(p);
			q = p;
			p = p->lchild;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->rchild;
		}
	 } 
}

void Lorder_Trave(BiTree &T)//先遍历一个二叉树 
{
	if(T)
	{
		cout<<T->data;
		Lorder_Trave(T->lchild);
		Lorder_Trave(T->rchild);
	}
}
void B_order_Trave(BiTree &T)
{
	stack<BiNode> S;
	BiNode*p = new BiNode;
	p = T;
	BiNode* q = new BiNode;
	while(p||!S.empty())
	{
		if(p)
		{
			S.push(*p);
			p = p->lchild;
		}
		else
		{
			*q = S.top();
			cout<<q->data;
			S.pop();
			p = q->rchild;
		}
	}
 } 

void Border_Trave(BiTree &T)//中遍历一个二叉树
{
	if(T)
	{

		Border_Trave(T->lchild);
		cout<<T->data;
		Border_Trave(T->rchild);
	}
}


void R_Oreder_Trave(BiTree &T)
{
	BiNode *p = new BiNode; 
	BiNode *q = new BiNode;
	BiNode *r = new BiNode;
	stack<BiNode*> S;
	p = T;
	while(p||!S.empty())
	{
	if(p)
	{
		S.push(p);
		p = p->lchild;
	}
	else
	{
		q= S.top();
		if(q->rchild==NULL)
		{
			cout<<q->data;
			r = S.top();
			S.pop();
			
		 }
		 else if(q->rchild==r)
		 {
		 	cout<<q->data;
		 	r= S.top();
		 	S.pop();
		  } 
		  else
		  {
		  	p = q->rchild;
		  }
	}
	}
}
void Rorder_Trave(BiTree &T)//后遍历一个二叉树
{
	if(T)
	{

		Rorder_Trave(T->lchild);
		Rorder_Trave(T->rchild);
		cout<<T->data;
	}
}

int Depth(BiTree &T)//输出一个树的深度 
{
	if(T==NULL) 
		return 0;
	else 				/*当树不为空时，先遍历其左子树，当左子树不为空则继续遍历其左子树的左子树
						 若左子树为空，则遍历其右子树，遍历*/ 
	{
		int m,n;
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return m+1;
		else
			return n+1;
		 
	}
}

int NodeCount(BiTree &T)
{
	if(!T)
		return 0;
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

void Yecount(BiTree &T,int &count)
{
	if(T)
	{
		{if(T->lchild==NULL&&T->rchild==NULL)
			count++;
		Yecount(T->lchild,count);
		Yecount(T->rchild,count);
		}
	}
		

}

int Nodeone(BiTree &T)
{
	if(!T)
		return 0;
	if((T->lchild!=NULL&&T->rchild==NULL)||(T->rchild!=NULL&&T->lchild==NULL))
		return 1+Nodeone(T->lchild)+Nodeone(T->rchild);
	return Nodeone(T->lchild)+Nodeone(T->rchild);
}
int Nodetwo(BiTree &T)
{
	if(!T)
	return 0;
	if(T->lchild!=NULL&&T->rchild!=NULL)
		return Nodetwo(T->lchild)+Nodetwo(T->rchild)+1; 
 } 

void DoubleTreave(BiTree &T)
{
	if(T)
	{
		BiTree newTree;
		newTree = new BiNode;
		cout<<T->data;
		newTree=T;
		DoubleTreave(T->lchild);
		cout<<newTree->data;
		DoubleTreave(T->rchild);
		
	}
}
void CengCi_trave(BiTree& T)
{
	queue<BiNode*>Q;
	if(T)
	Q.push(T);
	BiNode * q = new BiNode;
	while(!Q.empty())
	{
		q = Q.front();
		Q.pop();
		cout<<q->data;
		if(q->lchild!=NULL)
		Q.push(q->lchild);
		if(q->rchild!=NULL)
		Q.push(q->rchild); 
	}
 } 
void Path(BiTree& T, char *l,int len)//将每一个叶子节点到根节点的路径输出 
{
	if (T)
	{	
		if(T->lchild==NULL&&T->rchild==NULL) 
		{
			cout<<T->data<<"-->";
			for(int i=len-1;i>0;i--)
			{
		
					cout<<l[i]<<"-->";
			}
			cout<<l[0];
			cout<<endl;
		}
	
		else
		{
			l[len++]=T->data;
			Path(T->lchild, l, len);
			Path(T->rchild, l, len);
		}
	}
}

void Change(BiTree &T)
{
	if (!T)
		return;
	else
	{
		BiTree temp = T->lchild;//创建一个中间变量，用来接收T->lchlid 
		T->lchild = T->rchild;	//将右子树赋值给左子树 
		T->rchild = temp;		//将中间变量赋值给右子树，也就是将原来的左子树赋值给右子树 
		Change(T->lchild);		//父辈交换成功后，交换子树的左子树的所有子树 
		Change(T->rchild);		//左子树交换到空树时，则交换父类子树的右子树 
	}
}

void Longest_path(BiTree &T,BiTree* &longpath,int &longest)
{
	BiNode *p = T;
	BiNode *q = new BiNode;
	BiNode *r = q;
	BiNode **path = new BiNode*[20];
	int len = 0;
	while(p||len>0)
	{
		if(p)
		{
		
			path[len++] = p;
			p = p->lchild;
		}
		else
		{
			q = path[len-1];
			if(q->rchild==NULL||q->rchild==r)
			{
				r = q;
				len--;
			}
			else
			 p = q->rchild;
		}
		if(len>longest)
		{
			for(int i=0;i<len;i++)
			{
				longpath[i] = path[i];
			}
			longest = len;
		}
	}
}
int main()
{

	char c[200]={0};
	int len=0;
	int count=0;
	BiTree T;
	Create(T);
	cout<<"先序遍历：递归";
	Lorder_Trave(T);
	cout<<"后序遍历：非递归";
	L_Order_Trave(T);
	cout<<endl;
	cout<<"中序遍历：递归" ;
	Border_Trave(T);
	cout<<"中序遍历：非递归";
	B_order_Trave(T); 
	cout<<endl;
	cout<<"后续遍历：递归";
	Rorder_Trave(T);
	cout<<"后序遍历：非递归";
	R_Oreder_Trave(T); 
	cout<<endl;
	cout<<"双序遍历：";
	DoubleTreave(T);
	cout<<endl;
	cout<<"深度为"<<Depth(T)<<endl;
	cout<<"总节点个数为"<<NodeCount(T)<<endl;
	Yecount(T,count);
	cout<<"叶子节点个数为"<<count<<endl;
	cout<<"度为一的节点个数为"<<Nodeone(T)<<endl;
	cout<<"根节点到叶子节点的各情况为： "<<endl;
	Path(T,c,len); 
	Change(T);
	cout << "左右子树交换成功！" << endl;
	cout<<"交换后"<<endl; 
	cout<<"先序遍历：" ;
	Lorder_Trave(T);
	cout<<endl;
	cout<<"后序序遍历：" ;
	Rorder_Trave(T);
	cout<<endl;
	cout<<"层次遍历：";
	CengCi_trave(T);
	cout<<endl;

    int longest = 0;
	BiNode **longpath = new BiNode*[20];
	Longest_path(T,longpath,longest);
	cout<<"最长路径为 ：";
	for(int i=0;i<longest;i++)
	{
		if (i<longest-1)
		cout<<longpath[i]->data<<"->";
		else
		cout<<longpath[i]->data;
	}
	cout<<"长度为 : "<<longest<<endl; 
	cout<<"度为2的节点个数为: "<<Nodetwo(T)<<endl;

	return 1;
	
}
