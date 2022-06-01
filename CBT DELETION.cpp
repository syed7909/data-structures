#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

class Completebinarytree
{
public:
	node *root, *temp;
	int maxnode, countnode, depth, level, hight, number;
	int lastnodedata;
	bool flag;
	Completebinarytree()
	{
		root = temp = NULL;
		maxnode = countnode = depth = level = hight = 0;
	}

	void insert(node* temp)
	{

		if (root == NULL)
		{
			root = new node;
			root->data = number;
			root->left = NULL;
			root->right = NULL;
			return;

		}

		if (temp->left != NULL&&depth<level)
		{
			depth++;
			insert(temp->left);
			depth--;
		}

		if (flag == true)
		{
			if (temp->left == NULL&&temp->right == NULL)
			{
				temp->left = new node;
				temp->left->data = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				flag = false;
				return;
			}

			else if (temp->left != NULL&&temp->right == NULL)
			{
				temp->right = new node;
				temp->right->data = number;
				temp->right->left = temp->right->right = NULL;
				flag = false;
				return;
			}
		}
		else
		{
			return;
		}

		if (temp->right != NULL&&depth < level)
		{
			depth++;
			insert(temp->right);
			depth--;
		}
	}

	int height(node *temp)
	{
		if (temp == NULL)
		{
			return 0;
		}
		else
		{
			int LD = height(temp->left);
			int RD = height(temp->right);

			if (LD > RD)
			{
				return (LD + 1);
			}

			else
			{
				return (RD + 1);
			}
		}
	}

	int levelfunction()
	{
		maxnode = pow(2, height(root)) - 1;
		if (countnode == maxnode)
		{
			return level = height(root);
		}
		else
		{
			return level = height(root) - 1;
		}


	}

	void inorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			inorder(temp->left);
			cout << temp->data << " ";
			inorder(temp->right);
		}
	}
	void levelorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			queue<node*> Q;
			Q.push(temp);
			while (!Q.empty())
			{
				node *current = Q.front();
				cout << current->data << " ";
				if (current->left != NULL)
				{
					Q.push(current->left);
				}
				if (current->right != NULL)
				{
					Q.push(current->right);
				}
				Q.pop();
			}

		}
		return;
	}



	int level_(node *temp)
	{
		int count = 0;

		{
			while (temp->left != NULL) 
			{
				temp = temp->left;
				count++;
			}
			return count;
		}
	}
	int fun_2(node *temp)
	{
		while (temp) {
			int left_level = level_(temp);
			int right_level = 0;
			if (temp->right!=NULL)
			 right_level = level_(temp->right)+1;

			int factor = left_level - right_level;
			if (factor == 0 && left_level == 1 && right_level == 1)
			{
				lastnodedata = temp->right->data;

				node* temp_1 = temp->right;
				temp->right = NULL;
				delete temp_1;
				return lastnodedata;
			}
			if (factor == 1)
			{
				if (temp->right == NULL)
				{
					lastnodedata = temp->left->data;
					node* temp_1 = temp->left;
					temp->left = NULL;
					delete temp_1;
					return lastnodedata;

				}
			}
			if (left_level == right_level)
				temp = temp->right;
			else if (left_level > right_level)
				temp = temp->left;
		}
	}

	void del(node *temp, int key)
	{
		if (temp == NULL)
		{
			return;
		}

		else
		{
			if (temp->data == key)
			{
				temp->data = lastnodedata;


			}
			del(temp->left, key);
			del(temp->right, key);


		}



	}

};


int main()
{


	Completebinarytree c;

	cout << "1-insert a node" << endl;
	cout << "2-Print Complete Binary Tree:" << endl;
	cout << "3-Exit The Program" << endl;
	cout << "4-Delete a Node" << endl;

	while (1)
	{
		cout << "Enter the  ";
		int key;
		cin >> key;

		if (key == 1)
		{
			cout << "Enter the insertion data: ";
			cin >> c.number;
			c.depth = 1;
			c.flag = true;
			c.countnode++;
			c.insert(c.root);
			c.levelfunction();

		}
		if (key == 2)
		{
			c.levelorder(c.root);
			cout << endl;
		}
		if (key == 3)
		{
			break;
		}
		if (key == 4)
		{
			cout << "Enter the data of deletion: ";
			int del_number;
			cin >> del_number;
			c.fun_2(c.root);
			c.countnode--;
			c.levelfunction();
			c.del(c.root, del_number);
		}

	}

	
	





return 0;
}
