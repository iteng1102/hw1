#include <cstddef>
#include <stdexcept>

#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  if (head_ == NULL){
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
    size_+=1;
  }
  else if (head_->last == ARRSIZE && head_ == tail_) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    Item* current = head_;
    current->next = newItem;
    tail_ = newItem;
    tail_->prev = current;
    size_+=1;
  }
  else if (tail_->last == ARRSIZE && head_!=tail_){
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    Item* current = tail_;
    current->next = newItem;
    newItem->prev = current;
    tail_ = newItem;
    size_+=1;

  }
  else{
    tail_->val[(tail_->last)] = val;
    tail_->last +=1;
    size_+=1;
  }
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  if (!empty()){
    if (head_== tail_){
      if (head_->first == head_->last){
        head_ = NULL;
        tail_ = NULL;
      }
      else {
        head_->val[head_->last-1].clear();
        head_->last-=1;
        size_-=1;
      }
    }
    else if (tail_->last == tail_->first+1){
        tail_->val[tail_->first].clear();
        tail_ = tail_->prev;
        size_-=1;
    }
    else {
      tail_->val[(tail_->last)-1].clear();
      tail_->last-=1;
      size_-=1;
    }
  }
}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
    if (head_== NULL && tail_ == NULL){
      Item* newItem = new Item();
      newItem->val[ARRSIZE-1] = val;
      newItem->first = ARRSIZE-1;
      newItem->last = ARRSIZE;
      head_ = newItem;
      tail_ = newItem;
      size_+=1;
    }
    else if (head_->first==0){
      Item* newItem = new Item();
      newItem->val[ARRSIZE-1] = val;
      newItem->first = ARRSIZE-1;
      newItem->last = ARRSIZE;
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
      size_+=1;
    }
    else{
      head_->val[(head_->first)-1] = val;
      head_->first-=1; 
      size_+=1;
    }
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  if (!empty()){
    if (head_==tail_){
      if (head_->first == head_->last){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
      }
      else{
        head_->val[head_->first].clear();
        head_->first+=1;
        size_-=1;
      }
    }
    else if (head_->last == head_->first+1){
      head_->val[head_->first].clear();
      Item* old = head_;
      head_ = head_->next;
      head_->prev = NULL;
      delete old;
      size_-=1;
    }
    else {
      head_->val[head_->first].clear();
      head_->first+=1;
      size_-=1;
    }
  }
}

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const{
  if (head_==tail_){
    return head_->val[head_->last-1];
  }
  else{
    return tail_->val[tail_->last-1];
  }
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* current = head_;
  size_t count = 0; 
  size_t length;
  if (loc>=size_){
    return NULL;
  }

  while (current!=NULL){
    if (loc<(current->last-current->first)+count){
      length = current->last-current->first;
      return &current->val[current->last-length+loc-count];
      }
    count += current->last-current->first;
    current = current -> next;
  }
  return NULL;
  delete current;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


