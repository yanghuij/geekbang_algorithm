//253. 普通平衡树
//https://www.acwing.com/problem/content/description/255/
#include <bits/stdc++.h>

using namespace std;

//树堆
struct Node{
    Node* left; //左孩子
    Node* right; //右孩子
    
    int key; //原始数据
    int val; //随机权值
    
    int cnt; //副本数
    int size; //子树大小
    
    Node(int data) {
        key = data;
        val = rand();
        cnt = 1;
        size = 1;
        
        left = right = nullptr;
    }
};

class Treap {
public:
    Treap() {
        //空Treap，包含两个保护节点
        root = new Node(-1e9);
        root->right = new Node(1e9);
        update(root);
    }
    
    //插入
    void Insert(int data) {
        root = Insert(root, data);
    }
    
    //删除
    void Remove(int data) {
        root = Remove(root, data);
    }
    
    //查询target的排名
    int GetRankByVal(int target) {
        //有保护节点，所以减1
        return GetRankByVal(root, target) - 1;
    }
    
    //查询排第rank名的元素
    int GetValByRank(int rank) {
        //有保护节点，所以加1
        return GetValByRank(root, rank + 1);
    }
    
    //查询target的前驱（小于target的最大值）
    int GetPre(int target) {
        int ans = -1e9;
        Node* p = root;
        
        while (p) {
            if (p->key == target) {
                if (p->left) {
                    p = p->left;
                    while (p->right) p = p->right;
                    ans = p->key;
                }
                break;
            } else if (p->key > target) {
                p = p->left;
            } else {
                if (p->key > ans) ans = p->key;
                p = p->right;
            }
        }
        
        return ans;
    }
    
    //查询target的后继（大于target的最小值）
    int GetNext(int target) {
        int ans = 1e9;
        Node* p = root;
        
        while (p) {
            if (p->key == target) {
                if (p->right) {
                    p = p->right;
                    while (p->left) p = p->left;
                    ans = p->key;
                }
                break;
            } else if (p->key > target) {
                if (p->key < ans) ans = p->key;
                p = p->left;
            } else {
                p = p->right;
            }
        }
        
        return ans;
    }
    
private:
    //在以p为根的子树中查询target的排名
    int GetRankByVal(Node* p, int target) {
        int left_size = p->left ? p->left->size : 0;
        
        if (target == p->key) {
            return left_size + 1;
        } else if (target < p->key) {
            return GetRankByVal(p->left, target);
        } else {
            return left_size + p->cnt + GetRankByVal(p->right, target);
        }
    }
    
    //以p为根的子树中查询第rank名的元素
    int GetValByRank(Node* p, int rank) {
        int left_size = p->left ? p->left->size : 0;
        
        if (rank <= left_size) {
            return GetValByRank(p->left, rank);
        } else if  (rank <= left_size + p->cnt) {
            return p->key;
        } else {
            return GetValByRank(p->right, rank - left_size - p->cnt);
        }
    }
    
    //以p为根的子树删除key，返回新的根
    //p旋转到叶子，删除
    Node* Remove(Node* p, int key) {
        if (p == nullptr) {
            return nullptr;
        }
        
        if (p->key == key) {
            if (p->cnt > 1) p->cnt--;
            else {
                if (!p->left && !p->right) {
                    delete p;
                    return nullptr; 
                }
                
                if (!p->right || (p->left && p->left->val > p->right->val)) {
                    p = zig(p);
                    p->right = Remove(p->right, key);
                } else {
                    p = zag(p);
                    p->left = Remove(p->left, key);
                }
            }
        } else if (p->key > key) {
            p->left = Remove(p->left, key);
        } else {
            p->right = Remove(p->right, key);
        }
        update(p);
        
        return p;
        
    }
    
    //以p为根的子树中插入data，返回新的根
    Node* Insert(Node* p, int key) {
        if (p == nullptr) {
            return new Node(key);
        }
        
        if (p->key == key) {
            p->cnt++;
        } else if (p->key > key) {
            p->left = Insert(p->left, key);
            //val不满足堆性质，左孩子绕p右旋，左孩子代替p成为新的根
            if (p->val < p->left->val) p = zig(p);
        } else {
            p->right = Insert(p->right, key);
            //val不满足堆性质，右孩子绕p左旋，右孩子代替p成为新的根
            if (p->val < p->right->val) p = zag(p);
        }
        update(p);
        
        return p;
        
    }
    
    //p的左孩子绕p右旋转
    Node* zig(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        update(p);
        update(q);
        return q;
    }
    
    //p的右孩子绕p左旋转
    Node* zag(Node* p) {
        Node* q = p->right;
        p->right = q->left;
        q->left = p;
        update(p);
        update(q);
        return q;
    } 
    
    //更新节点p的附加信息
    void update(Node* p) {
        int left_size = p->left ? p->left->size : 0;
        int right_size = p->right ? p->right->size : 0;
        
        p->size = left_size + right_size + p->cnt;
    }
    
    Node* root;
};

int main() {
    Treap treap;
    int n;
    cin >> n;
    
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        
        switch (opt) {
        case 1:
            treap.Insert(x);
            break;
        case 2:
            treap.Remove(x);
            break;
        case 3:
            cout << treap.GetRankByVal(x) << endl;
            break;
        case 4:
            cout << treap.GetValByRank(x) << endl;
            break;
        case 5:
            cout << treap.GetPre(x) << endl;
            break;
        case 6:
            cout << treap.GetNext(x) << endl;
            break;
        }
    }
    
}