#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};

class imp
{
	node *root;
	node *temp;
	node *temp1;
	node *n;

	int d = 0;
public:
	imp()
	{
		root = NULL;
		temp = root;
	}

	node* insert(node *temp, int data)
	{

		if (root == NULL)
		{

			n = new node;
			root = n;
			root->data = data;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			return root;
		}
		
		if (temp->data == data)
		{
		
			cout << "Dublicate: " << data << endl;
			
			return temp;
			
		}
		

		if (temp->data > data)
		{
			if (temp->left == NULL)
			{
				temp->left = new node;
				temp->left->data = data;
				temp->left->left = NULL;
				temp->left->right = NULL;
				return temp;
			}
			else
			{
				return	insert(temp->left, data);
			}
		}
		if (temp->data < data)
		{
			if (temp->right == NULL)
			{
				temp->right = new node;
				temp->right->data = data;
				temp->right->left = NULL;
				temp->right->right = NULL;
				return temp;
			}
			else
			{
				return	insert(temp->right, data);
			}
		}
	}

	void preorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			cout << temp->data;
			preorder(temp->left);
			preorder(temp->right);

		}
	}

	void del(node *temp, int data)
	{

		if (root->data == data)
		{
			return;
		}
		if (temp->data > data)
		{

			if (temp->left != NULL)
			{

				if (temp->left->data == data && (temp->left->left == NULL) && (temp->left->right == NULL))
				{
					temp1 = temp->left;
					temp->left = NULL;
					delete temp1;
					return;
				}
				if (temp->left->data == data && (temp->left->right == NULL) && (temp->left->left != NULL))
				{
					temp1 = temp->left;
					temp->left = temp->left->left;
					delete temp1;
					return;
				}
				if (temp->left->data == data && (temp->left->right != NULL) && (temp->left->left == NULL))
				{
					temp1 = temp->left;
					temp->left = temp->left->right;
					delete temp1;
					return;
				}

				if (temp->left->data == data && (temp->left->right != NULL) && (temp->left->left != NULL))
				{
					min_left(temp->left->left);
					temp->left->data = d;
					return;
				}

				else
				{

					return del(temp->left, data);
				}
			}
		}

		if (temp->data < data)
		{

			if (temp->right != NULL)
			{

				if (temp->right->data == data && (temp->right->left == NULL) && (temp->right->right == NULL))
				{
					temp1 = temp->right;
					temp->right = NULL;
					delete temp1;
					return;
				}

				if (temp->right->data == data && (temp->right->right == NULL) && (temp->right->left != NULL))
				{
					temp1 = temp->right;
					delete temp1;
					temp->right = temp->right->left;
					return;
				}
				if (temp->right->data == data && (temp->right->right != NULL) && (temp->right->left == NULL))
				{
					temp->right = temp->right->right;
					temp1 = temp->right;
					delete temp1;
					return;
				}

				if (temp->right->data == data && (temp->right->right != NULL) && (temp->right->left != NULL))
				{
					min_right(temp->right->right);
					temp->right->data = d;
					return;

				}
				else
				{
					return del(temp->right, data);
				}


			}
		}
	}

	void min_right(node *temp)
	{
		if (temp->left == NULL)
		{
			
			d = temp->data;
			del(root, temp->data);
			return;
		}
		else
		{
			min_right(temp->left);
		}
	}

	void min_left(node *temp)
	{
		if (temp->right == NULL)
		{

			d = temp->data;
			del(root, temp->data);
			return;
		}
		else
		{
			min_left(temp->right);
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

	void postorder(node *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else
		{
			postorder(temp->right);
			cout << temp->data << " ";
			postorder(temp->left);
		}
	}
	

	void search(node *temp,int data)
	{
			if (temp == NULL)
			{
				return;
			}
			else
			{
				if (temp->data == data)
				{
					cout << "Search found" << endl;
					return;
				}
				else
				{
					search(temp->left,data);
					search(temp->right,data);
				}
			}
		
	}

};


int main()
{
	imp bst;
	node *r = NULL;
	node *print;
	r = bst.insert(r, 15);
	bst.insert(r, 13);
	bst.insert(r, 11);
	bst.insert(r, 14);
	bst.insert(r, 10);
	bst.insert(r, 15);
	bst.insert(r, 15);
	bst.insert(r, 15);
	bst.inorder(r);
	cout << endl;
	bst.del(r, 13);
	bst.inorder(r);
	cout<<endl;

}
