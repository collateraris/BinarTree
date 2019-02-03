#pragma once
#include <memory>
#include <any>
#include <iostream>
#include <cmath>
using namespace std;
const float epsilon = 0.01;

namespace BinTree
{
	template <typename T>
	class TreeNode {
	public:
		T key;
		shared_ptr<TreeNode<T>> left;
		shared_ptr<TreeNode<T>> right;
	};
	class BinTreeSearch {
	public:
		void insert(float val);
		void search(float val);
		void reset(float val);
		void search_min();
		void search_max();
		void inorder_walk();
	protected:
		void tree_insert(float val, shared_ptr<TreeNode<float>> &node);
		bool tree_search(float val, shared_ptr<TreeNode<float>> &node);
		bool tree_reset(float val, shared_ptr<TreeNode<float>> &node);
		void inorder_tree_walk( shared_ptr<TreeNode<float>> &node );
		bool op_delete(shared_ptr<TreeNode<float>> &node);
		shared_ptr<TreeNode<float>>& tree_min( shared_ptr<TreeNode<float>> &node);
		shared_ptr<TreeNode<float>>& tree_max(shared_ptr<TreeNode<float>> &node);
		shared_ptr<TreeNode<float>> start;
	};

}
