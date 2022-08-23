#include <iostream>
#include <queue>

using namespace std;


class Node
{
public:
    int value;
    Node* right;
    Node* left;

    Node(int v):value(v),right(NULL),left(NULL)
    {
    }
};

class BinaryST
{
public:
    Node* root;
public:
    BinaryST():root(NULL)
    {
    }

    //insertion recursion
    Node* insertion(Node* r, int n)
    {
        if(r == NULL)
        {
            Node* newnode = new Node(n);
            r = newnode;
        }
        else if(n > r->value)
            r->right = insertion(r->right, n);
        else if(n <= r->value)
            r->left = insertion(r->left, n);

        return r;
    }

    //insertion user
    void insertion(int x)
    {
        root = insertion(root, x);
    }


    //traverse dfs pre order
    void traversePreOrder(Node* r)
    {
        if(r == NULL)
            return;
        cout << r->value << " ";
        traversePreOrder(r->left);
        traversePreOrder(r->right);
    }

    //traverse user
    void traversePreOrder()
    {
        traversePreOrder(root);
    }

    void traverseInOrder(Node* r)
    {
        if(r == NULL)
            return;
        traverseInOrder(r->left);
        cout << r->value << " ";
        traverseInOrder(r->right);
    }

    void traverseInOrder()
    {
        traverseInOrder(root);
    }

    void traversePostOrder(Node* r)
    {
        if(r == NULL)
            return;
        traversePostOrder(r->left);
        traversePostOrder(r->right);
        cout << r->value << " ";
    }

    void traversePostOrder()
    {
        traversePostOrder(root);
    }

    //void searching
    void searching(Node* r, int k)
    {
        if(r == NULL)
        {
            cout << "not found";
            return;
        }
        if(k == r->value)
        {
            cout << "founded";
            return;
        }
        else if(k > r->value)
            searching(r->right, k);
        else if(k <= r->value)
            searching(r->left, k);
    }

    //void searching user
    void searching(int k)
    {
        searching(root, k);
    }

    //return searching
    Node* searching1(Node* r, int k)
    {
        Node* temp;

        if(r == NULL)
        {
            temp = NULL;
        }
        else if(k == r->value)
        {
            temp = r;
        }
        else if(k > r->value)
            temp = searching1(r->right, k);
        else if(k <= r->value)
            temp = searching1(r->left, k);

        return temp;
    }

    //return searching user
    Node* searching1(int k)
    {
        return searching1(root, k);
    }

    //max
    int maximum(Node* r)
    {
        Node* temp = r;
        while(temp->right != NULL)
            temp = temp->right;

        return temp->value;

    }

    //max user
    int maximum()
    {
        return maximum(root);
    }

    //max address
    Node* maximumAdd(Node* r)
    {
        Node* temp = r;
        while(temp->right != NULL)
            temp = temp->right;

        return temp;

    }


    //min
    int minimum(Node* r)
    {
        Node* temp = r;
        while(temp->left != NULL)
            temp = temp->left;

        return temp->value;

    }

    //min user
    int minimum()
    {
        return minimum(root);
    }

    //min address
    Node* minimumAdd(Node* r)
    {
        Node* temp = r;
        while(temp->left != NULL)
            temp = temp->left;

        return temp;

    }

    //insertion loop
    Node* insertLoop(Node* r, int k)
    {
        Node* newnode = new Node(k);

        if(r == NULL)
        {
            r = newnode;
            return r;
        }

        Node* temp = r;
        while(true)
        {
            if(k > temp->value)
            {
                if(temp->right == NULL)
                {
                    temp->right = newnode;
                    return r;
                }
                temp = temp->right;
            }
            else if(k <= temp->value)
            {
                if(temp->left == NULL)
                {
                    temp->left = newnode;
                    return r;
                }
                temp = temp->left;
            }

        }
    }

    //insertion loop user
    void insertLoop(int k)
    {
        root = insertLoop(root, k);
    }

    //searching loop
    Node* searchLoop(Node* r, int k)
    {
        if(r == NULL)
            return NULL;

        Node* temp = r;
        while(true)
        {
            if(temp == NULL)
                return NULL;
            else if(k == temp->value)
                return temp;
            else if(k < temp->value)
                temp = temp->left;
            else if(k > temp->value)
                temp = temp->right;
        }
    }

    //searching loop user
    bool searchLoop(int k)
    {
        Node* temp = searchLoop(root, k);
        if(!temp)
        {
            cout << "not done";
            return false;
        }
        else
        {
            cout << "done";
            return true;
        }
    }

    /*
    //remove loop
    Node* deletion(Node* r, int k)
    {
        //null root
        if(r == NULL)
            return NULL;

        //find k node
        Node* del = r;
        Node* parent = NULL;
        while(true)
        {
            if(del == NULL)
            {
                break;
            }
            else if(k < del->value)
            {
                parent = del;
                del = del->left;
            }
            else if(k > del->value)
            {
                parent = del;
                del = del->right;
            }
            else if(k == del->value)
            {
                break;
            }
        }

        //now we have location of k

        //item k not found
        if(del == NULL)
            return NULL;

        //node k is a leaf node
        if(!del->left && !del->right)
        {
            if(del->value < parent->value)
            {
                delete del;
                parent->left = NULL;
            }
            else
            {
                delete del;
                parent->right = NULL;
            }
        }
        else if(del->left && !del->right) //one child on the left
        {
            del->value = del->left->value;
            delete del->left;
            del->left = NULL;
        }
        else if(!del->left && del->right) //one child on the right
        {
            del->value = del->right->value;
            delete del->right;
            del->right = NULL;
        }
        else            //two children
        {
            Node* mx1 = maximumAdd(del->left);
            del->value = mx1->value;
            delete mx1;
        }

        return r;

    }

    //remove loop user
    void deletion(int k)
    {
        root = deletion(root, k);
    }
    */

    //remove recursion
    Node* removing(Node* r, int k)
    {
        //null root
        if(r == NULL)
            return NULL;

        //starting find k location
        if(k < r->value)
            r->left = removing(r->left, k);
        else if(k > r->value)
            r->right = removing(r->right, k);
        //here we reach the k node
        else
        {
            //k is a leaf node
            if(!r->left && !r->right)
            {
                r = NULL;
            }
            else if(r->left && !r->right) //k has on child on the left
            {
                r->value = r->left->value;
                delete r->left;
                r->left = NULL;
            }
            else if(!r->left && r->right) //one child on the right
            {
                r->value = r->right->value;
                delete r->right;
                r->right = NULL;
            }
            else
            {
                Node* mx = maximumAdd(r->left);
                r->value = mx->value;
                r->left = removing(mx, mx->value);

            }
        }

        return r;
    }

    //remove recursion user
    void removing(int k)
    {
        root = removing(root, k);
    }

    int getHeight(Node* r)
    {
        if(r == NULL)
            return -1;
        int l = getHeight(r->left);
        int ri = getHeight(r->right);

        return 1+ max(l, ri);
    }

    int getHeight()
    {
        return getHeight(root);
    }


    // Breadth First Traverse BFS
    void BFS()
    {
        if(root == NULL)
            return;

        queue <Node*> q;

        Node* curr = root;
        q.push(curr);

        while(!q.empty())
        {
            cout << curr->value << " ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
            q.pop();
            curr = q.front();
        }
        cout << "\n";
    }

};

//========================================================//

//Another way

int main()
{
    BinaryST bt;


    bt.insertLoop(45);
    bt.insertLoop(15);
    bt.insertLoop(10);
    bt.insertLoop(12);
    bt.insertLoop(20);
    bt.insertLoop(79);
    bt.insertLoop(55);
    bt.insertLoop(50);
    bt.insertLoop(90);


    bt.traversePreOrder();
    cout << "\n";
    bt.traverseInOrder();
    cout << "\n";
    bt.traversePostOrder();
    cout << "\n";
    bt.BFS();
    cout << "\n";

    cout << bt.maximum() << endl;
    cout << bt.minimum() << endl;
    cout << bt.getHeight() << endl;

    bt.removing(12);
    bt.removing(15);
    bt.removing(79);

    cout << "\n";

    bt.traversePreOrder();

    return 0;
}
