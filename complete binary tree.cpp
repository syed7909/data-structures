#include<iostream>
#include<math.h>
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
			cout << temp->data;
			inorder(temp->right);
		}
	}



};


int main()
{

	
	Completebinarytree c;

	cout << "1-insert" << endl;
	cout << "2-Show CBT" << endl;

	while (1)
	{
		cout << "Enter the Key: ";
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
			cout<<c.height(c.root);

		}
		if (key == 2)
		{
			c.inorder(c.root);
			cout << endl;
		}
		
	}

	
	c.inorder(c.root);
	


return 0;
}
