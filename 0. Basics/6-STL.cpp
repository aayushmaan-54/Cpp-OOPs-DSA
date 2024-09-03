#include <bits/stdc++.h>
using namespace std;

void explainPair() {
    pair<int, double> p = {4, 4.5};
    cout << p.first << ", " << p.second << endl;

    pair<int, pair<char, float>> x = {1, {'a', 4.5}};
    cout << x.first << ", " << x.second.first << ", " << x.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << endl;
}

void explainVector() {
    vector<int> v;

    v.push_back(1); // push element to back of vector
    v.emplace_back(2); // directly push element to back

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v1(5, 100); // [100, 100, 100, 100, 100]
    vector<int> v2(5); // [0, 0, 0, 0, 0]

    vector<int> v3(5, 20); // [20, 20, 20, 20, 20]
    vector<int> v4(v3); // v4 = [20, 20, 20, 20, 20]

    vector<int>::iterator it = v1.begin(); // iterator to 1st element of v1

    it++;
    cout << *(it) << endl;

    it += 2;
    cout << *(it) << endl;

    // Correct usage of iterator functions
    vector<int>::iterator it1 = v1.end(); // points to one past the last element
    vector<int>::reverse_iterator it2 = v1.rbegin(); // points to the last element

    cout << v1[0] << " = " << v1.at(0) << endl; // checks whether the index is within the valid range
    cout << v1.back() << endl; // returns last element

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;

    for (auto it : v1) { // range-based for loop
        cout << it << ", ";
    }
    cout << endl;

    v1.erase(v1.begin() + 1); // remove element at index 1
    v1.erase(v1.begin() + 2, v1.begin() + 4); // remove elements from index 2 to index 3

    vector<int> v5(2, 100); // [100, 100]
    v5.insert(v5.begin(), 300); // [300, 100, 100]
    v5.insert(v5.begin() + 1, 2, 10); // [300, 10, 10, 100, 100]

    vector<int> copy(2, 50); // [50, 50]
    v5.insert(v5.begin(), copy.begin(), copy.end()); // [50, 50, 300, 10, 10, 100, 100]

    cout << v5.size() << endl; // 7

    v5.pop_back(); // removes last element

    // v1 = [10, 20], v2 = [30, 40]
    v1.swap(v2); // v1 = [30, 40], v2 = [10, 20]

    v5.clear(); // erases the entire vector

    cout << v5.empty() << endl; // true if vector is empty
}

void explainList() { // similar to vector but has additional operations for front
    list<int> ls;

    ls.push_back(2); // [2]
    ls.emplace_back(4); // [2, 4]

    ls.push_front(5); // [5, 2, 4]
    ls.emplace_front(1); // [1, 5, 2, 4]

    // List operations are similar to vector: begin, end, rbegin, clear, rend, size, insert, swap
}

void explainDeque() {
    deque<int> dq;

    dq.push_back(1); // [1]
    dq.emplace_back(2); // [1, 2]
    dq.push_front(3); // [3, 1, 2]

    dq.pop_back(); // [3, 1]
    dq.pop_front(); // [1]

    cout << dq.back() << endl; // returns last element
    cout << dq.front() << endl; // returns first element

    // Deque operations are similar to vector: begin, end, rbegin, clear, rend, size, insert, swap
}

void explainStack() {
    stack<int> st;

    st.push(1); // [1]
    st.push(2); // [2, 1]
    st.push(3); // [3, 2, 1]
    st.push(3); // [3, 3, 2, 1]
    st.emplace(5); // [5, 3, 3, 2, 1]
    st.pop(); // [3, 3, 2, 1]

    cout << st.top() << endl; // 3
    cout << st.size() << endl; // 4
    cout << st.empty() << endl; // false

    stack<int> st1, st2;
    st1.swap(st2); // swaps the contents of st1 and st2
}

void explainQueue() {
    queue<int> q;

    q.push(1); // [1]
    q.push(2); // [1, 2]
    q.emplace(4); // [1, 2, 4]

    q.back() += 5; // [1, 2, 9]

    cout << q.back() << endl; // 9
    cout << q.front() << endl; // 1

    q.pop(); // [2, 9]
}

void explainPriorityQ() {
  // Max-heap priority_queue (default)
  priority_queue<int> pq;

  pq.push(5);      // [5]
  pq.push(2);      // [5, 2]
  pq.push(3);      // [5, 3, 2]
  pq.emplace(10);  // [10, 5, 3, 2]

  cout << pq.top() << endl; // 10

  pq.pop();        // [5, 3, 2]

  // Min-heap priority_queue (using greater<int>)
  priority_queue<int, vector<int>, greater<int>> pq_min;

  pq_min.push(5);      // [5]
  pq_min.push(2);      // [2, 5]
  pq_min.push(8);      // [2, 5, 8]
  pq_min.emplace(10);  // [2, 5, 8, 10]

  cout << pq_min.top() << endl; // 2
}

void explainSet() {
  set<int> st; // Store everything in sorted and unique way
  st.insert(1); // [1]
  st.emplace(2); // [1, 2]
  st.insert(2); // [1, 2]
  st.insert(4); // [1, 2, 4]
  st.insert(3); // [1, 2, 3, 4]

  auto it = st.find(3); // Find the iterator to the element 3
  auto it_end = st.find(6); // If element not in set, returns st.end()

  // Erase the element 4
  st.erase(4); // [1, 2, 3]

  // Erase elements in the range [it, it_end) (though it_end is st.end(), so no elements are erased)
  // Note: Since st.end() is one past the last element, erasing in this case will not change the set
  st.erase(it, it_end); // [1, 2] (since `it_end` is not valid in this context)

  int cnt = st.count(1); // Return 1 if element is available, 0 if not
  cout << "Count of 1: " << cnt << endl; // Output the count of element 1

  // Corrected variable names for lower_bound and upper_bound
  auto it_lower = st.lower_bound(2); // Returns iterator to the first element not less than 2
  auto it_upper = st.upper_bound(3); // Returns iterator to the first element greater than 3

  cout << "lower_bound(2): " << (it_lower != st.end() ? to_string(*it_lower) : "not found") << endl; // Output: 2
  cout << "upper_bound(3): " << (it_upper != st.end() ? to_string(*it_upper) : "not found") << endl; // Output: not found (since 3 is the last element)
}

void explainMultiSet() {
  // multiset allows duplicate elements
  multiset<int> ms;
  ms.insert(1); // [1]
  ms.insert(1); // [1, 1]
  ms.insert(1); // [1, 1, 1]

  ms.erase(1); // Erases all occurrences of 1, multiset becomes empty

  int cnt = ms.count(1); // Count occurrences of 1, should be 0 now
  cout << "Count of 1: " << cnt << endl; // Output: 0

  // Re-insert values for demonstration
  ms.insert(1); // [1]
  ms.insert(1); // [1, 1]

  // Erase a single occurrence of 1
  ms.erase(ms.find(1)); // Erases one occurrence of 1, multiset becomes [1]

  // Re-insert for further demonstration
  ms.insert(1); // [1, 1]
  ms.insert(2); // [1, 1, 2]

  // Erase elements in range [first, last) where `last` is one past the end
  auto it_start = ms.find(1);
  auto it_end = ms.find(2); // Points to the first element greater than 1
  ms.erase(it_start, it_end); // Erases elements from `it_start` to `it_end` (exclusive of `it_end`)

// Print remaining elements
  cout << "Remaining elements: ";
  for (const auto& elem : ms) {
    cout << elem << " "; // Output: 2
  }
  cout << endl;
}

void explainUset() {
  unordered_set<int> ust;
  // lower_bound, upper_bound fucntion
  // does not works, rest all functions are same
  // as above, it doesnot stores in any 
  // particular order it has better complexity
  // than set in most cases except some when collision happens
}

void explainMap() {
  // Create maps with different key-value types
  map<int, int> mpp1; // Key: int, Value: int
  map<int, pair<int, int>> mpp2; // Key: int, Value: pair<int, int>
  map<pair<int, int>, int> mpp3; // Key: pair<int, int>, Value: int

  // Working with mpp1
  mpp1[1] = 2;             // {1: 2}
  mpp1.emplace(3, 1);      // {1: 2, 3: 1}
  mpp1.insert({2, 4});     // {1: 2, 2: 4, 3: 1}

  // Working with mpp3
  mpp3[{2, 3}] = 10;       // { (2, 3): 10 }

  // Print contents of mpp1
  cout << "Contents of mpp1:" << endl;
  for (const auto& it : mpp1) {
    cout << it.first << ", " << it.second << endl;
  }

  // Access elements
  cout << "Value for key 1: " << mpp1[1] << endl; // 2
  cout << "Value for key 5: " << mpp1[5] << endl; // 0 (default value for int)

  // Find method
  auto it = mpp1.find(3);
  if (it != mpp1.end()) {
    cout << "Value for key 3: " << it->second << endl; // 1
  }

  // Lower and upper bound methods
  auto lb = mpp1.lower_bound(2);
  auto ub = mpp1.upper_bound(2);

  cout << "Lower bound for key 2: " << lb->first << ", " << lb->second << endl; // 2, 4
  cout << "Upper bound for key 2: " << (ub != mpp1.end() ? ub->first : -1) << endl; // 3

  // Print contents of mpp3
  cout << "Contents of mpp3:" << endl;
  for (const auto& it : mpp3) {
    cout << "(" << it.first.first << ", " << it.first.second << ") -> " << it.second << endl;
  }

  // Erase, swap, size, empty are similar to other containers
}

void explainMultiMap() {
  // everything same as map, only it can store duplicate keys, everything in sorted way
  // only mpp[key] cannot be used here
}

void explainUnorderedMap() {
  // same as set and unordered_set
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first; // Example comparison function
}

void explainExtra() {
  vector<int> v = {3, 1, 4, 1, 5}; // Example vector for sorting
  int n = 5; // Example size
  int a[] = {3, 1, 4, 1, 5};

  sort(a, a + n); // Sort in ascending order
  sort(v.begin(), v.end()); // Sort vector in ascending order

  sort(a + 2, a + 4); // Sort subarray

  sort(a, a + n, greater<int>()); // Sort in descending order

  pair<int, int> b[] = {{1, 2}, {2, 1}, {4, 1}};
  int m = 3; // Size of pair array
  sort(b, b + m, comp); // Sort pair array with custom comparator

  int num = 7;
  int cnt = __builtin_popcount(num); // Count set bits

  long long numLL = 165785324789123LL;
  int cntLL = __builtin_popcountll(numLL); // Count set bits for long long

  string s = "123";
  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end())); // Permutations

  int maxi = *max_element(a, a + n); // Find max element
  cout << "Max element: " << maxi << endl;
}

int main() {
  explainPair();
  explainVector();
  explainList();
  explainDeque();
  explainStack();
  explainQueue();
  explainPriorityQ();
  explainSet();
  explainMultiSet();
  explainUset();
  explainMap();
  explainMultiMap();
  explainUnorderedMap();
  explainExtra();

  return 0;
}