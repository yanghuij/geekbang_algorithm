//253. ��ͨƽ����
//https://www.acwing.com/problem/content/description/255/
#include <bits/stdc++.h>

using namespace std;

//����
struct Node{
    Node* left; //����
    Node* right; //�Һ���
    
    int key; //ԭʼ����
    int val; //���Ȩֵ
    
    int cnt; //������
    int size; //������С
    
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
        //��Treap���������������ڵ�
        root = new Node(-1e9);
        root->right = new Node(1e9);
        update(root);
    }
    
    //����
    void Insert(int data) {
        root = Insert(root, data);
    }
    
    //ɾ��
    void Remove(int data) {
        root = Remove(root, data);
    }
    
    //��ѯtarget������
    int GetRankByVal(int target) {
        //�б����ڵ㣬���Լ�1
        return GetRankByVal(root, target) - 1;
    }
    
    //��ѯ�ŵ�rank����Ԫ��
    int GetValByRank(int rank) {
        //�б����ڵ㣬���Լ�1
        return GetValByRank(root, rank + 1);
    }
    
    //��ѯtarget��ǰ����С��target�����ֵ��
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
    
    //��ѯtarget�ĺ�̣�����target����Сֵ��
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
    //����pΪ���������в�ѯtarget������
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
    
    //��pΪ���������в�ѯ��rank����Ԫ��
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
    
    //��pΪ��������ɾ��key�������µĸ�
    //p��ת��Ҷ�ӣ�ɾ��
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
    
    //��pΪ���������в���data�������µĸ�
    Node* Insert(Node* p, int key) {
        if (p == nullptr) {
            return new Node(key);
        }
        
        if (p->key == key) {
            p->cnt++;
        } else if (p->key > key) {
            p->left = Insert(p->left, key);
            //val����������ʣ�������p���������Ӵ���p��Ϊ�µĸ�
            if (p->val < p->left->val) p = zig(p);
        } else {
            p->right = Insert(p->right, key);
            //val����������ʣ��Һ�����p�������Һ��Ӵ���p��Ϊ�µĸ�
            if (p->val < p->right->val) p = zag(p);
        }
        update(p);
        
        return p;
        
    }
    
    //p��������p����ת
    Node* zig(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        update(p);
        update(q);
        return q;
    }
    
    //p���Һ�����p����ת
    Node* zag(Node* p) {
        Node* q = p->right;
        p->right = q->left;
        q->left = p;
        update(p);
        update(q);
        return q;
    } 
    
    //���½ڵ�p�ĸ�����Ϣ
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