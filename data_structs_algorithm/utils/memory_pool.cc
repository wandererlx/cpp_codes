//
// Created by shawnunili on 2019/7/26.
//

#include "memory_pool.h"
#include <iostream>
#include<string>
#include <list>

using namespace std;

char* MemoryPool::myMalloc(const int memSize) {
    //采用首次适应算法
    list<Node*>::iterator it;
    if (memSize <= m_First_Count) {
        it = first.begin();
        while (it != first.end()) {
            if (((*it)->len) >= memSize && (*it)->flag == true) {
                (*it)->flag = false;
                int temp = (*it)->len;
                (*it)->len = memSize;
                if (temp - memSize > 0) {
                    Node* obj = new Node;
                    obj->flag = true;
                    obj->len = temp - memSize;
                    obj->offset = (*it)->offset + memSize;
                    it++;
                    first.insert(it, obj);
                    it--;
                    it--;
                    m_First_Count -= memSize;
                    cout << "malloc " << memSize << " in first memery" << endl;
                    return m_First_Address + (*it)->offset;
                }
            }
            it++;
        }

    }

    if (memSize <= m_Second_Count) {
        it = second.begin();
        while (it != second.end()) {
            if (((*it)->len) >= memSize && (*it)->flag == true) {
                (*it)->flag = false;
                int temp = (*it)->len;
                (*it)->len = memSize;
                if (temp - memSize > 0) {
                    Node* obj = new Node;
                    obj->flag = true;
                    obj->len = temp - memSize;
                    obj->offset = (*it)->offset + memSize;
                    it++;
                    second.insert(it, obj);
                    it--;
                    it--;
                    m_Second_Count -= memSize;
                    cout << "malloc " << memSize << "in second memery" << endl;
                    return m_Second_Address + (*it)->offset;
                }
            }
            it++;
        }

    }

    if (memSize <= m_Third_Count) {
        it = third.begin();
        while (it != third.end()) {
            if (((*it)->len) >= memSize && (*it)->flag == true) {
                (*it)->flag = false;
                int temp = (*it)->len;
                (*it)->len = memSize;
                if (temp - memSize > 0) {
                    Node* obj = new Node;
                    obj->flag = true;
                    obj->len = temp - memSize;
                    obj->offset = (*it)->offset + memSize;
                    it++;
                    third.insert(it, obj);
                    it--;
                    it--;
                    m_Third_Count -= memSize;
                    cout << "malloc " << memSize << "in third memery" << endl;
                    return m_Third_Address + (*it)->offset;
                }
            }
            it++;
        }

    }

    cout << "no memery\n";
    return NULL;

}
/************************************************************************/
/* 算法思路是第一步定位这个指针位于哪一个内存块，第二步在对应内存块中找到*/
/*其node，然后判断node前后是否都为有效内存，也就是没有被利用的内存块*/
/************************************************************************/
void MemoryPool::memFree(void* address_arg) {
    char* freeAddress = static_cast<char*>(address_arg);
    int offset;
    list<Node*>::iterator it;
    if (freeAddress >= m_First_Address && freeAddress < (m_First_Address + 1024))//位于第一块
    {
        offset = freeAddress - m_First_Address;
        it = first.begin();

        while (it != first.end())//定位offset
        {
            if (offset == (*it)->offset) {
                break;
            }

            it++;
        }
        if (it == first.end())//没有找到offset
        {
            cout << "In first memery,there is no memery of freeaddress" << endl;
            return;
        }

        if ((*it)->flag == true)//找到offset，但是这块内存没有分配
        {
            cout << "In first memery,the freeAddress is valid,you can't free it" << endl;
            return;
        }
        (*it)->flag = true;

        int len = (*it)->len;
        int count = 0;
        if (it != first.end())//判断it后继节点是否被分配
        {
            it++;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            }
            it--;
        }
        if (it != first.begin()) {
            it--;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            } else {
                it++;
            }
        }
        (*it)->len = len;
        it++;
        while (count--) {
            it = first.erase(it);//erase返回删除节点的后继节点

        }

        cout << "free success" << endl;
        return;

    } else if (freeAddress >= m_Second_Address && freeAddress < (m_Second_Address + 1024 * 2))//位于第二块
    {
        offset = freeAddress - m_Second_Address;
        it = second.begin();

        while (it != second.end())//定位offset
        {
            if (offset == (*it)->offset) {
                break;
            }

            it++;
        }
        if (it == second.end())//没有找到offset
        {
            cout << "In second memery,there is no memery of freeaddress" << endl;
            return;
        }

        if ((*it)->flag == true)//找到offset，但是这块内存没有分配
        {
            cout << "In second memery,the freeAddress is valid,you can't free it" << endl;
            return;
        }
        (*it)->flag = true;

        int len = (*it)->len;
        int count = 0;
        if (it != second.end())//判断it后继节点是否被分配
        {
            it++;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            }
            it--;
        }
        if (it != second.begin()) {
            it--;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            } else {
                it++;
            }
        }
        (*it)->len = len;
        it++;
        while (count--) {
            it = second.erase(it);
        }

        cout << "free success" << endl;
        return;
    } else if (freeAddress >= m_Third_Address && freeAddress < (m_Third_Address + 1024 * 4))//位于第三块
    {
        offset = freeAddress - m_Third_Address;
        it = third.begin();

        while (it != third.end())//定位offset
        {
            if (offset == (*it)->offset) {
                break;
            }

            it++;
        }
        if (it == third.end())//没有找到offset
        {
            cout << "In third memery,there is no memery of freeaddress" << endl;
            return;
        }

        if ((*it)->flag == true)//找到offset，但是这块内存没有分配
        {
            cout << "In third memery,the freeAddress is valid,you can't free it" << endl;
            return;
        }
        (*it)->flag = true;

        int len = (*it)->len;
        int count = 0;
        if (it != third.end())   //判断it后继节点是否被分配
        {
            it++;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            }
            it--;
        }
        if (it != third.begin()) {
            it--;
            if ((*it)->flag == true) {
                len += (*it)->len;
                count++;
            } else {
                it++;
            }
        }
        (*it)->len = len;
        it++;
        while (count--) {
            it = third.erase(it);
        }

        cout << "free success" << endl;
        return;
    } else {
        cout << "the memery to be freed is invalid\n";
    }
    return;
}