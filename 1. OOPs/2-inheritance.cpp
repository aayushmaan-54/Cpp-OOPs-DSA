#include <iostream>
using namespace std;

// Base class for Single Inheritance
class SingleParent {
public:
  void singleMethod() {
    cout << "Single Inheritance: SingleParent method\n";
  }
};

// Single Inheritance
class SingleChild : public SingleParent {
  // Inherits singleMethod() from SingleParent
};

// Base classes for Multiple Inheritance
class Parent1 {
  public:
    void parent1Method() {
      cout << "Multiple Inheritance: Parent1 method\n";
    }
};

class Parent2 {
  public:
    void parent2Method() {
      cout << "Multiple Inheritance: Parent2 method\n";
    }
};

// Multiple Inheritance
class MultipleChild : public Parent1, public Parent2 {
  // Inherits parent1Method() from Parent1 and parent2Method() from Parent2
};

// Base class for Multilevel Inheritance
class Grandparent {
  public:
    void grandparentMethod() {
      cout << "Multilevel Inheritance: Grandparent method\n";
    }
};

// Multilevel Inheritance
class Parent : public Grandparent {
  // Inherits grandparentMethod() from Grandparent
};

class MultilevelChild : public Parent {
  // Inherits grandparentMethod() from Parent (which inherits from Grandparent)
};

// Hybrid Inheritance
class Base {
  public:
    void baseMethod() {
      cout << "Hybrid Inheritance: Base method\n";
    }
};

class HybridParent1 : public Base {
  public:
    void hybridParent1Method() {
      cout << "Hybrid Inheritance: HybridParent1 method\n";
    }
};

class HybridParent2 : public Base {
  public:
    void hybridParent2Method() {
      cout << "Hybrid Inheritance: HybridParent2 method\n";
    }
};

class HybridChild : public HybridParent1, public HybridParent2 {
  // Inherits hybridParent1Method() from HybridParent1 and hybridParent2Method() from HybridParent2
};

// Hierarchical Inheritance
class HierarchicalParent {
  public:
    void hierarchicalMethod() {
      cout << "Hierarchical Inheritance: HierarchicalParent method\n";
    }
};

class HierarchicalChild1 : public HierarchicalParent {
  // Inherits hierarchicalMethod() from HierarchicalParent
};

class HierarchicalChild2 : public HierarchicalParent {
  // Inherits hierarchicalMethod() from HierarchicalParent
};

int main() {
  // Single Inheritance
  SingleChild singleChild;
  singleChild.singleMethod();

  // Multiple Inheritance
  MultipleChild multipleChild;
  multipleChild.parent1Method();
  multipleChild.parent2Method();

  // Multilevel Inheritance
  MultilevelChild multilevelChild;
   multilevelChild.grandparentMethod();

  // Hybrid Inheritance
  HybridChild hybridChild;
  hybridChild.hybridParent1Method();
  hybridChild.hybridParent2Method();

  // Hierarchical Inheritance
  HierarchicalChild1 hierarchicalChild1;
  hierarchicalChild1.hierarchicalMethod();

  HierarchicalChild2 hierarchicalChild2;
  hierarchicalChild2.hierarchicalMethod();

  return 0;
}



/*

(i) Single Inheritance:  One class inherits from one parent class.
  +-----------+
  | Parent    |
  +-----------+
        |
        v
  +-----------+
  | Child     |
  +-----------+

(ii) Multiple Inheritance: A class inherits from two or more parent classes.
  +-----------+      +-----------+
  | Parent1   |      | Parent2   |
  +-----------+      +-----------+
        |                |
        +----------------+
                     |
                     v
               +-----------+
               | Child     |
               +-----------+

(iii) Multilevel Inheritance: A class inherits from another class, which is itself a child class.
  +-----------+
  | Grandparent|
  +-----------+
        |
        v
  +-----------+
  | Parent    |
  +-----------+
        |
        v
  +-----------+
  | Child     |
  +-----------+

(iV) Hybrid Inheritance: A combination of multiple and multilevel inheritance. it is not maditory to be multiple and multilevel it can be any type of inheritance
      +-----------+
     |   Base    |
     +-----------+
        /   \
       v     v
+-----------+  +-----------+
| Parent1   |  | Parent2   |
+-----------+  +-----------+
        \     /
         \   /
          \ /
           v
      +-----------+
      |   Child   |
      +-----------+

(V) Hierarchical Inheritance: Multiple classes inherit from a single parent class.
      +-----------+
      | Parent    |
      +-----------+
        /    \
       v      v
+-----------+  +-----------+
| Child1    |  | Child2    |
+-----------+  +-----------+

*/