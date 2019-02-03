#include "pch.h"
#include "BinTree.h"
using namespace std;
using namespace BinTree;

namespace BinTree {
	void BinTreeSearch::insert(float val) {
		tree_insert(val, this->start);
	}
	void BinTreeSearch::tree_insert(float val, shared_ptr<TreeNode<float>> &node) {
		if (!node) {
			node = make_shared<TreeNode<float>>();
			node->key = val;
		}
		else {
			if (val < node->key) {
				if (node->left) {
					tree_insert(val, node->left);
				}
				else {
					node->left = make_shared<TreeNode<float>>();
					node->left->key = val;
				}
			}
			else if (val >= node->key) {
				if (node->right) {
					tree_insert(val, node->right);
				}
				else {
					node->right = make_shared<TreeNode<float>>();
					node->right->key = val;
				}
			}
		}
	}

	void BinTreeSearch::search(float val) {
		if (tree_search(val, this->start)) {
			cout << val <<  " Find!" << endl;
		}
		else {
			cout << val << " Lose!" << endl;
		}
	}

	bool BinTreeSearch::tree_search(float val, shared_ptr<TreeNode<float>> &node) {

		if (!node) {
			return false;
		}
		if (abs(val - node->key) < epsilon) {
			return true;
		}
		if (val < node->key) {
			return tree_search(val, node->left);
		}
		if (val >= node->key) {
			return tree_search(val, node->right);
		}
	}

	void BinTreeSearch::reset(float val) {
		if (tree_reset(val, this->start)) {
			cout << "Complete deleted" << endl;
		}
		else {
			cout << "Not found! deleted is failed" << endl;
		}
	}

	bool BinTreeSearch::tree_reset(float val, shared_ptr<TreeNode<float>> &node) {
		if (!node) {
			return false;
		}
		if (abs(val - node->key) < epsilon) {
			return op_delete(node);
		}
		if (val < node->key) {
			return tree_reset(val, node->left);
		}
		if (val >= node->key) {
			return tree_reset(val, node->right);
		}

	}

	bool BinTreeSearch::op_delete(shared_ptr<TreeNode<float>> &node) {
		if (node) {
			//variant 1
			if (!node->left  and node->right) {
				node = move(node->right);
				return true;
			}
			//variant 2
			if (!node->right and node->left) {
				node = move(node->left);
				return true;
			}
			//variant 3
			if (node->right and !node->right->left) {
				node->right->left = move(node->left);
				node = move(node->right);
				return true;
			}
			//variant 4
			if (node->right and node->left) {
				shared_ptr<TreeNode<float>> y = move(tree_min(node->right));
				shared_ptr<TreeNode<float>> z = tree_min(node->right);
				z->left = move(y->right); 
				y->left = move(node->left);
				shared_ptr<TreeNode<float>> r = move(node->right);
				node = move(y);
				node->right = move(r);
				return true;
			}

			
		}
		return false;
	}

	void BinTreeSearch::search_min() {
		shared_ptr<TreeNode<float>> tr = tree_min(this->start);
		if (tr) {
			cout << "Min_ " << tr->key << endl;
		}
		else {
			cout << "Min_  NULL " << endl;
		}
	}

	shared_ptr<TreeNode<float>>& BinTreeSearch::tree_min( shared_ptr<TreeNode<float>> &node) {
		if (node) {
			if (node->left) {
				return tree_min(node->left);
			}
			else {
				return node;
			}
		}
		else {
			return node;
		}
	}

	void BinTreeSearch::search_max() {
		shared_ptr<TreeNode<float>> tr = tree_max(this->start);
		if (tr) {
			cout << "Max_ " << tr->key << endl;
		}
		else {
			cout << "Max_  NULL " << endl;
		}
	}

	shared_ptr<TreeNode<float>>& BinTreeSearch::tree_max(shared_ptr<TreeNode<float>> &node) {
		if (node) {
			if (node->right) {
				return tree_max(node->right);
			}
			else {
				return node;
			}
		}
		else {
			return node;
		}
	}

	void BinTreeSearch::inorder_walk() {
		inorder_tree_walk(this->start);
	}

	void BinTreeSearch::inorder_tree_walk( shared_ptr<TreeNode<float>> &node) {
		if (node) {
			cout << " Node " << node->key << endl;
			inorder_tree_walk(node->left);
			inorder_tree_walk(node->right);
		 }
	}




}