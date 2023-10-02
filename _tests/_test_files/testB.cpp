#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/bst_functions/bst_functions.h"
#include "../../includes/bst/bst.h"

bool test_print(bool debug){
  tree_node<int>* ourRoot = new tree_node<int>(25); 
  tree_insert(ourRoot, 39); 
  tree_insert(ourRoot, 12); 
  tree_print(ourRoot, 0, cout); //ok so far print is working 
  return true; 
}

bool test_pre_order(bool debug){
  tree_node<int>* ourRoot = new tree_node<int>(25); 
  tree_insert(ourRoot, 12); 
  tree_insert(ourRoot, 39); 

  if(debug){
    cout<<"printing the simple case pre order:\n"; 
    pre_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"printing the complicated case pre order:\n"; 
    tree_insert(ourRoot, 45); 
    tree_insert(ourRoot, 10); 
    tree_insert(ourRoot, 14); 
    tree_print(ourRoot, 0, cout); 
    pre_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"testing pre_order_string\n"; 
    string preOrder = pre_order_string(ourRoot); 
    cout<<"preOrder: "<<preOrder<<endl; 
  }
  return true; 
}

bool test_post_order(bool debug){
  tree_node<int>* ourRoot = new tree_node<int>(25); 
  tree_insert(ourRoot, 12); 
  tree_insert(ourRoot, 39);  

  if(debug){
    cout<<"printing the simple case post order:\n"; 
    post_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"printing the complicated case post order:\n"; 
    tree_insert(ourRoot, 45); 
    tree_insert(ourRoot, 10); 
    tree_insert(ourRoot, 14); 
    tree_print(ourRoot, 0, cout); 
    post_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"testing post_order_string\n"; 
    string postOrder = post_order_string(ourRoot); 
    cout<<"postOrder: "<<postOrder<<endl; 
  }

}

bool test_in_order(bool debug){
  tree_node<int>* ourRoot = new tree_node<int>(25); 
  tree_insert(ourRoot, 12); 
  tree_insert(ourRoot, 39);  

  if(debug){
    cout<<"printing the simple case in order:\n"; 
    in_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"printing the complicated case in order:\n"; 
    tree_insert(ourRoot, 30);
    tree_insert(ourRoot, 45); 
    tree_insert(ourRoot, 10); 
    tree_insert(ourRoot, 14); 
    tree_print(ourRoot, 0, cout); 
    in_order(ourRoot, cout); 
  }

  if(debug){
    cout<<"testing in_order_string\n"; 
    string inOrder = in_order_string(ourRoot); 
    cout<<"inOrder: "<<inOrder<<endl; 
  }
  return true;
}

bool test_clear(bool debug){
  tree_node<int>* ourRoot = new tree_node<int>(25); 
  tree_insert(ourRoot, 12); 
  tree_insert(ourRoot, 39);  

  if(debug){
    cout<<"before clear: "<<endl; 
    tree_print(ourRoot, 0, cout); //gotta make sure height is set correctly to
    tree_clear(ourRoot); 
    cout<<"after clear: "<<endl; 
    tree_print(ourRoot, 0, cout); 
  }
}

bool test_erase(bool debug){

  if(true){
    srand(time(0)); 
    cout<<"testing: case 1: "<<endl; 
    //[28][44][34][38][80][62][62][62][66][66][84][72][72][74][74][78][80][80]
    int arr[] = {24,24,28, 38, 62,62,66,66, 72,72,74,74,78,80,80, 80,84}; 
    BST<int> mTree(arr, 17); 
    cout<<"tree before erase: "<<endl; 
    cout<<mTree<<endl; 
    mTree.erase(62);
    cout<<mTree<<endl;

    //erasing 62 
    /*
    while(!mTree.empty()){
      int randIndex = rand() % 17; 
      cout<<"erasing: "<<arr[randIndex]<<endl; 
      mTree.erase(arr[randIndex]); 
      cout<<mTree<<endl; 
    }*/
  }
  if(false){
    cout<<"erase with duplicates case: \n"; 
    tree_node<int>* ourRoot = new tree_node<int>(10); 
    tree_insert(ourRoot, 10); 
    tree_insert(ourRoot, 10); 

    cout<<"before erase: \n"; 
    tree_print(ourRoot, 0, cout); 
    
    cout<<"after erase: \n"; 
    tree_erase(ourRoot, 10); 
    tree_erase(ourRoot, 10); 
    tree_print_debug(ourRoot, 0, cout); 
    cout<<endl; 

  }
  if(false){
    tree_node<int>* ourRoot = new tree_node<int>(25); 
    tree_insert(ourRoot, 12); 
    tree_insert(ourRoot, 39); 

    cout<<"erasing 12: \n"; 
    tree_print(ourRoot, 0, cout); 
    tree_erase(ourRoot, 12); 
    tree_print_debug(ourRoot, 0, cout);
  }

  if(false){
    tree_node<int>* ourRoot = new tree_node<int>(25); 
    tree_insert(ourRoot, 12); 
    tree_insert(ourRoot, 39); 
    cout<<"simple erase case root:\n"; 
    tree_print(ourRoot, 0, cout); 

    cout<<"erasing root 25: \n";
    tree_erase(ourRoot, 25);
    tree_erase(ourRoot, 39);
    tree_erase(ourRoot, 12);
    tree_print_debug(ourRoot, 0, cout); 
    cout<<boolalpha<<"empty?"<<(ourRoot == NULL)<<endl; 
  }

  if(false){
    tree_node<int>* ourRoot = new tree_node<int>(25); 
    tree_insert(ourRoot, 12); 
    tree_insert(ourRoot, 39); 
    tree_insert(ourRoot, 10);
    tree_insert(ourRoot, 14);  
    cout<<"complex erase case 12:\n"; 
    tree_print(ourRoot, 0, cout); 

    cout<<"erasing root 12: \n";
    tree_erase(ourRoot, 12); //what if duplicate values ?
    tree_print(ourRoot, 0, cout); 
  }
  return true; 
}

bool test_copy(bool debug){
  if(debug){
    tree_node<int>* ourRoot = new tree_node<int>(25); 
    tree_insert(ourRoot, 12); 
    tree_insert(ourRoot, 39); 
    cout<<"simple case copy: "<<endl; 
    tree_node<int>* copyRoot; 
    copyRoot = tree_copy(ourRoot); 
    tree_print_debug(copyRoot, 0, cout); 
  } 

  if(debug){
    tree_node<int>* ourRoot = new tree_node<int>(25); 
    tree_insert(ourRoot, 12); 
    tree_insert(ourRoot, 39);  
    tree_insert(ourRoot, 10); 
    tree_insert(ourRoot, 14); 
    cout<<"complex case copy: "<<endl; 
    tree_node<int>* copyRoot; 
    copyRoot = tree_copy(ourRoot); 
    tree_print_debug(copyRoot, 0, cout); 
  }

  return true; 
}

bool test_add(bool debug){
  if(debug){
    tree_node<int>* srcTree = new tree_node<int>(10); 
    tree_insert(srcTree, 13); 
    tree_insert(srcTree, 9);
    cout<<"srcTree: \n"; 
    tree_print(srcTree, 0, cout);   

    tree_node<int>* destTree = new tree_node<int>(11); 
    tree_insert(destTree, 8);
    tree_insert(destTree, 15); 
    cout<<"destTree: \n"; 
    tree_print(destTree, 0, cout); 

    cout<<"added tree:\n"; 
    tree_add(destTree, srcTree); 
    tree_print(destTree, 0, cout); 

  }

  if(debug){
    tree_node<int>* srcTree = new tree_node<int>(10); 
    tree_insert(srcTree, 3); 
    tree_node<int>* destTree = new tree_node<int>(15); 
    tree_insert(destTree, 5); 

    cout<<"asymmetrical case: \n"; 
    cout<<"src tree: \n"; 
    tree_print(srcTree, 0, cout); 

    cout<<"dest tree: \n"; 
    tree_print(destTree, 0, cout); 

    cout<<"added tree:\n"; 
    tree_add(destTree, srcTree);
    tree_print(destTree, 0, cout);
  }

  if(debug){
    //whack case 
    tree_node<int>* srcTree = new tree_node<int>(25); 
    tree_insert(srcTree, 24);  
    tree_insert(srcTree, 28); 
    cout<<"src tree\n"; 
    tree_print(srcTree, 0, cout); 

    tree_node<int>* destTree = new tree_node<int>(10); 
    tree_insert(destTree, 16); 
    tree_insert(destTree, 18); 
    tree_insert(destTree, 4); 
    tree_insert(destTree, 6); 
    tree_insert(destTree, 41); 
    tree_insert(destTree, 26);
    tree_insert(destTree, 3);

    cout<<"root tree\n"; 
    tree_print(destTree, 0, cout);

    cout<<"added tree\n"; 
    tree_add(destTree, srcTree); 
    tree_print(destTree, 0, cout); 

  }

  if(debug){
    tree_node<int>* srcTree = new tree_node<int>(11); 
    tree_insert(srcTree, 17);  
    tree_insert(srcTree, 19); 
    tree_insert(srcTree, 15);
    tree_insert(srcTree, 5);
    tree_insert(srcTree, 9); 
    tree_insert(srcTree, 3); 
    tree_insert(srcTree, 1); 

    cout<<"complex tree case: src tree\n"; 
    tree_print(srcTree, 0, cout);  

    tree_node<int>* destTree = new tree_node<int>(10); 
    tree_insert(destTree, 16); 
    tree_insert(destTree, 18); 
    tree_insert(destTree, 4); 
    tree_insert(destTree, 6); 
    tree_insert(destTree, 14); 
    tree_insert(destTree, 12); 
    tree_insert(destTree, 0);   

    cout<<"complex tree case: dest tree\n"; 
    tree_print(destTree, 0, cout);   //ok something off about how this tree was inserted but we'll see 

    cout<<"added tree: \n";
    tree_add(destTree,srcTree); 
    tree_print(destTree, 0, cout);

  }
}

bool test_sort_tree(bool debug){
  if(debug){
    int a[]= {0,1,2}; 
    cout<<"testing tree from sort simple case: \n"; 
    tree_node<int>* myTree = tree_from_sorted_list(a, 3); 
    tree_print_debug(myTree, 0, cout); 
  }

  if(true){
    int a[]= {0,1,2,3,4,5}; 
    cout<<"testing tree from sort simple case: \n"; 
    tree_node<int>* myTree = tree_from_sorted_list(a, 6); 
    tree_print_debug(myTree, 0, cout); 
  }
}

bool test_erase_all(bool debug){
  if(debug){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
    BST<int> mBTree(arr, 4);
  

    cout<<"before erase: "<<endl; 
    cout<<mBTree<<endl; 

    for(int i = 0 ; i < 4; i++){
      cout<<"erasing: "<<i<<endl; 
      mBTree.erase(i); 
      cout<<mBTree<<endl; 
      cout<<boolalpha<<"mBtree empty?: "<<mBTree.empty()<<endl; 
    }
    
    cout<<boolalpha<<"tree empty?: "<<(mBTree.empty())<<endl; 
  }

  if(debug){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
    BST<int> mBtree(arr, 16); 

    cout<<"before erase: "<<endl; 
    cout<<mBtree<<endl;

    mBtree.clear_all(); 
    cout<<"after clear: "<<endl; 
    cout<<mBtree<<endl; 
    cout<<boolalpha<<"tree empty?: "<<mBtree.empty()<<endl; 

  }
}

bool test_sort_one_arg(bool debug){
  if(debug){
    int arr[] = {0,1,2,3,4,5,-1}; 
    tree_node<int>* ourRoot = tree_from_sorted_list(arr); 
    cout<<"new tree: "<<endl; 
    tree_print(ourRoot, 0, cout);
  }
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_PRINT, testPrint){
  EXPECT_EQ(1, test_print(false)); 
}

TEST(TEST_PRE_ORDER, testPreOrder){
  EXPECT_EQ(1, test_pre_order(false)); 
}

TEST(TEST_POST_ORDER, testPostOrder){
  EXPECT_EQ(1, test_post_order(false)); 
}

TEST(TEST_IN_ORDER, testInOrder){
  EXPECT_EQ(1, test_in_order(false));
}

TEST(TEST_BST_FUNCTIONS, testClear){
  EXPECT_EQ(1, test_clear(false));
}

TEST(TEST_BST_FUNCTIONS, testErase){
  EXPECT_EQ(1, test_erase(true));
}

TEST(TEST_BST_FUNCTIONS, testCopy){
  EXPECT_EQ(1, test_copy(false)); 
}

TEST(TEST_BST_FUNCTION, testAdd){
  EXPECT_EQ(1, test_add(false)); 
}

TEST(TEST_BST_FUNCTIONS, testTreeFromList){
  EXPECT_EQ(1, test_sort_tree(true)); 
}

TEST(TEST_BST_FUNCTION, testEraseAll){
  EXPECT_EQ(1, test_erase_all(false)); 
}

TEST(TEST_BST_FUNCTIONS, testSortOneArg){
  EXPECT_EQ(1, test_sort_one_arg(false));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

