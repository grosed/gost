

#include <orbtree.h>

#include <iostream>


struct rank_function {
    typedef double  argument_type;
    typedef unsigned int result_type;
    unsigned int operator()(const double& key) const {
        return 1;
    }
};

auto find_key(const auto& tree,const auto& key)
{
  auto it = tree.find(key);
  if(it == tree.end())
    {
      throw std::runtime_error("key not found\n");  
    }
  return tree.get_sum_node(it);
}

auto lower_bound_key(const auto& tree,const auto& key)
{
  auto it = tree.lower_bound(key);
  if(it == tree.end())
    {
      throw std::runtime_error("lower bound for key value not found\n");  
    }
  return tree.get_sum_node(it);
}


auto lower_bound_sum(const auto& tree,const auto& sum)
{
  auto it = tree.lower_bound_rank(sum);
  if(it == tree.end())
    {
      throw std::runtime_error("lower bound for sum value does not exist\n");  
    }
  return *it;
}

auto remove(auto& tree, const auto& key)
{
  return tree.erase(key);
}

int main()
{

  // map with the above function
  orbtree::simple_multiset<double,rank_function> ost;
  
  // insert element
  ost.insert(1.1);
  ost.insert(1000.1);
  ost.insert(-3.13);
  
  
  // ...
  // calculate sum of function for element with key == 1000
  std::cout << lower_bound_sum(ost,1) << std::endl;
  std::cout << find_key(ost,1.1) << std::endl;
  remove(ost,1.1);
  std::cout << lower_bound_sum(ost,1) << std::endl;
  
  return 0;
}


/* these are the basic methods I need for a gost all O(log(n))
lb_key 
lb_sum - done

find_key - done
find_sum

ub_key
ub_sum

insert
remove

*/


