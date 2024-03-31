/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*dummy = new Node(1);
        Node* tempH = head;
        Node tempC = dummy;
        while(tempH){
            tempC->next = new Node(tempH->val);//deep copy bnaye store hue dummy m
            tempC = tempC->next;
            tempH = tempH->next;
        }
        Node* duplicate = dummy->next; // deep copy duplicate m 
        Node* a = head;
        Node* b= duplicate;
        dummy = new Node(-1);// duplicate original copy 
        Node* tempD = dummy;

        while(a){
            tempD->next = a; //phle original
            a =a->next;
            tempD = tempD->next;
            tempD->next = b; //phir duplicate
            b= b->next;
            tempD =tempD->next;
        }
        dummy = dummy->next; //dono aagye isme
        Node* t1 = dummy;
        Node* t2 ;
        while(t1){
            t2 = t1->next; // deep copy t2 m
            if(t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;
        }

        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);//alag krne k lia deep copy
        t1= d1;
        t2 = d2;
        Node* t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }

        t2->next = NULL; //deep copy
        t1->next = NULL;
        d1 = d1->next;
        d2 = d2->next; //deep copy contain by d2

        return d2;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public: //using map
    Node* copyRandomList(Node* head) {
        Node*dummy = new Node(1);
        Node* tempH = head;
        Node* tempC = dummy;
        while(tempH){
            tempC->next = new Node(tempH->val);//deep copy bnaye store hue dummy m
            tempC = tempC->next;
            tempH = tempH->next;
        }
        Node* deep = dummy->next; //duplicate contain node of deep copy
        unordered_map<Node*,Node*> mp;
        tempH = head;
        dummy = deep;
        // mapping to original node with duplicate node
        while(tempH){
            mp[tempH] = dummy;
            dummy = dummy->next;
            tempH= tempH->next;
        }
        
        // traverse in map for mark the random pointer
        for(auto it:mp){
            tempH = it.first; //original
            dummy = it.second; //duplicate
            if(tempH->random){
                Node* orgRandom = tempH->random; // take org random and store it 
                dummy->random = mp[orgRandom];; // mark the random of duplicate with random in mapping of orginal random
            }
        }

        return deep;
    }
};