class MyTreeNode {
    TreeNode* node;
    int level;
    public:
    MyTreeNode(TreeNode* n, int l){
        node = n;
        level = l;
    }
    int getLevel(){
        return level;
    }
    TreeNode* getNode(){
        return node;
    }
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(!root){
            return output;
        }
        
        int level = 0;
        MyTreeNode node(root, level);
        
        queue<MyTreeNode>myQueue;
        myQueue.push(node);
        vector<int> subVector;
        output.push_back(subVector);
        
        while(!myQueue.empty()){
            MyTreeNode node = myQueue.front();
            
            if(node.getLevel() + 1 > output.size()){
                vector<int> subVector;
                output.push_back(subVector);
            }
            output[node.getLevel()].push_back(node.getNode()->val);
            
            myQueue.pop();
            
            if(node.getNode()->left != NULL){
                MyTreeNode node2(node.getNode()->left, node.getLevel() + 1);
                myQueue.push(node2);
            }
            
            if(node.getNode()->right != NULL){
                MyTreeNode node3(node.getNode()->right, node.getLevel() + 1);
                myQueue.push(node3);
            }
            
        }
        
        return output;
    }
    
};
