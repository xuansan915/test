#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H
#include <string>
#include <iostream>

typedef void (*TimeFunc)()    ;
struct TimeItem
{
    int     nTimeID;    //id
    int     nEndTime;   //终止时间
    int     nCount;     //  累计定时次数
    int     nElapse;     //每次间隔时间
    TimeFunc fTimeFunc;
    std::string Print()
    {
        std::string str;
        str += "{nTimeID:";
        str += std::to_string(nTimeID);
        str += ",nEndTime:";
        str += std::to_string(nEndTime);
        str += "}";
        return str;
    }

    bool operator< (const TimeItem& other)
    {
        if(nEndTime < other.nEndTime)
        {
            return true;
        }
        else if(nEndTime > other.nEndTime)
        {
            return false;
        }
        else
        {
            return nTimeID < other.nTimeID;
        }
    }
    bool operator== (const TimeItem& other)
    {
        return nTimeID == other.nTimeID && nEndTime == other.nEndTime;
    }
};

template <class T>
class Node
{
public:
    Node():next(nullptr),pre(nullptr)
    {

    }
    Node<T> *next;
    Node<T> *pre;
    T data;
};

template <class T>
class ordered_list
{
    public:
        ordered_list();
        virtual ~ordered_list();

        void insert(Node<T>*pInsert);
        bool erase(Node<T>* pDel);

        Node<T>* Head() {return m_pHead;}
        Node<T>* End() {return m_pEnd;}

        void Print();
    protected:

    private:
        Node<T>*   m_pHead;
        Node<T>*   m_pEnd;
};


template <class T>
ordered_list<T>::ordered_list():m_pHead(nullptr),m_pEnd(nullptr)
{
    //ctor
}

template <class T>
ordered_list<T>::~ordered_list()
{
    //dtor
}

template <class T>
void ordered_list<T>::insert(Node<T>* pInsert)
{
    //std::cout <<"insert  "<< pInsert->data.nTimeID<<" "<<pInsert->data.nEndTime<<std::endl;
    if(m_pHead == nullptr)
    {
        m_pHead = pInsert;
        m_pEnd = pInsert;
        return ;
    }
    else if(pInsert->data < m_pHead->data)
    {
        Node<T>* pTemp = m_pHead;
        m_pHead = pInsert;
        m_pHead->next = pTemp;
        pTemp->pre = m_pHead;

        return ;
    }

    Node<T>* pCurr = m_pHead->next;
    while(pCurr && pCurr->data < pInsert->data)
    {
        pCurr = pCurr->next;
    }
    //末尾了 加到最后
    if(pCurr == nullptr)
    {
        m_pEnd->next = pInsert;
        pInsert->pre = m_pEnd;
        m_pEnd = pInsert;
    }
    else
    {
        //插入到pCurr之前
        Node<T>* pTmp = pCurr->pre;
        pTmp->next = pInsert;
        pInsert->pre = pTmp;
        pInsert->next = pCurr;
        pCurr->pre = pInsert;

    }
}

template <class T>
bool ordered_list<T>::erase(Node<T>* pDel)
{
    //std::cout <<"erase  "<< pDel->data.nTimeID<<" "<<pDel->data.nEndTime<<std::endl;
    Node<T>* pCurr = m_pHead;
    if(pCurr == pDel)
    {
        m_pHead = nullptr;
        m_pEnd = nullptr;
        return true;
    }
    else if(pDel == m_pEnd)
    {
        Node<T>* pTmp = m_pEnd->pre;
        pTmp->next = nullptr;
        m_pEnd = pTmp;
        return true;
    }
    pCurr = pCurr->next;
    while(pCurr)
    {
        if(pCurr->data == pDel->data)
        {

            std::cout << pCurr->data.nTimeID<<" "<<pCurr->data.nEndTime<<std::endl;

            Node<T>* pPre = pCurr->pre;
            Node<T>* pNext = pCurr->next;
            pPre->next = pNext;
            pNext->pre = pPre;
            return true;
        }
        pCurr = pCurr->next;
    }
    return false;
}

template <class T>
void ordered_list<T>::Print()
{
    std::string msg;
    Node<T>* pCurr = m_pHead;
    while(pCurr)
    {
        msg += pCurr->data.Print();
        pCurr = pCurr->next;
    }
    std::cout <<msg<<std::endl;
}



#endif // ORDERED_LIST_H









