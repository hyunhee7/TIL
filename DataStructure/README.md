# 자료구조

## 그래프
* 노드와 간선을 모아놓은 자료구조
* 네트워크 모델
* 루트 노드의 개념이 없다.
* 부모 - 자식의 개념이 없다.
* DFS, BFS로 순회가 이루어진다.


## 트리
* 비선형 자료구조
* 나무를 뒤집어 놓았다고 하여 Tree라 부른다. 
* 값이 들어간 곳을 노드(node), 데이터를 이어주는 선을 엣지(edge)라고 한다.
* 그래프의 한 종류이다.
* 노드가 N개인 트리는 N-1개의 간선이 존재한다.
* 자식 노드는 하나의 부모 노드만 가진다.

[참고](https://ratsgo.github.io/data%20structure&algorithm/2017/10/21/tree/)

### 노드
트리는 루트노드를 갖고, 0개 이상의 자식 노드를 갖는다.
```java
class Node{
	public int name;
    public Node[] children; //Node배열을 통해 여러개의 자식 노드를 갖을 수 있음을 알 수 있다
}
```

### 트리의 종류
- Binary Search Tree(BST)
- Complete Binary Tree
- Full Binary Tree
- Perfect Binary Tree

### 트리 순회
노드를 체계적인 방법으로 방문하는 과정을 말합니다. 하나도 빠뜨리지 않고, 정확히 한 번만 중복없이 방문해야 합니다.



- 전위순회(preorder)
	- 1.Left 2.Root 3.Right
- 중위순회(inorder)
	- 1.Root 2.Left 3.Right
- 후위순회(postorder)
	- 1.Left 2.Right 3.Root

코드 구현 
- [강의 참고](https://www.youtube.com/watch?v=QN1rZYX6QaA)

```java    
    /*
     *       (1)  
     *     /     \
     *    (2)    (3)
     *   /  \    
     *  (4) (5)     
     */
    class Node{
        int data;
        Node left;
        Node right;
    }

    class Tree{
        public Node root;
        public void setRoot(Node node) {
            this.root = node;
        }
        public Node getRoot() {
            return root;
        }
        public Node makeNode(Node left, int data, Node right) {
            Node node = new Node();
            node.data = data;
            node.left = left;
            node.right = right;
            return node;
        }
        public void inorder(Node node) {
            if (node!=null) {
                inorder(node.left);
                System.out.println(node.data);
                inorder(node.right);
            }
        }
        public void preorder(Node node) {
            if(node!=null) {
                System.out.println(node.data);
                preorder(node.left);
                preorder(node.right);
            }
        }
        public void postorder(Node node) {
            if(node!=null) {
                postorder(node.left);
                postorder(node.right);
                System.out.println(node.data);
            }
        }
    }
    public class BinaryTree_order {

        public static void main(String[] args) {
            Tree t = new Tree();
            Node n4 = t.makeNode(null, 4, null);
            Node n5 = t.makeNode(null, 5, null);
            Node n2 = t.makeNode(n4, 2, n5);
            Node n3 = t.makeNode(null, 3, null);
            Node n1 = t.makeNode(n2, 1, n3);
            t.setRoot(n1);
            t.inorder(t.getRoot());
            System.out.println("---------");
            t.preorder(t.getRoot());
            System.out.println("---------");
            t.postorder(t.getRoot());
        }

    }
```