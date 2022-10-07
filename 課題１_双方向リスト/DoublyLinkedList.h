#pragma once
#include<string>

// @brief 成績データを格納する構造体
struct ResultData
{
public:
	std::string score;
	std::string name;
};

// @brief 双方向リストのクラス
// @brief 別名bi-directional list
class DoublyLinkedList
{
public:
	// @brief 双方向リストのノード
	// @brief 構造体ResultDataを格納している
	struct Node {
		DoublyLinkedList::Node* pPrevious = nullptr;
		DoublyLinkedList::Node* pNext = nullptr;
		ResultData resultData;
	};

	// @brief 双方向リストのイテレータ
	// @brief *演算子でイテレータが示すデータにアクセスできます
	class ConstIterator {
		friend DoublyLinkedList;
	public:
		//コンストラクタ
		ConstIterator();
		ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode);

		// @brief 次の要素に移動します
		//        次の要素に移動したイテレータを返します
		ConstIterator operator++();
		// @brief 次の要素に移動します
		//        次の要素に移動していないイテレータを返します
		ConstIterator operator++(int n);
		// @brief 前の要素に移動します
		//        前の要素に移動したイテレータを返します
		ConstIterator operator--();
		// @brief 前の要素します
		//        前の要素に移動していないイテレータを返します
		ConstIterator operator--(int n);

		// @brief 末尾方向に指定した数だけ移動したコンストイテレータを返します
		ConstIterator operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したコンストイテレータを返します
		ConstIterator operator-(int n);

		// @brief イテレータが示すコンスト要素の参照を取得します
		const ResultData& operator*();
		// @brief イテレータが示すコンスト要素の参照を取得します
		const ResultData* operator->();//何故かポインタを返さないといけない
		// @brief コピーコンストラクタ
		ConstIterator(const ConstIterator& obj);
		
		// @brief イテレータを比較します
		bool operator==(ConstIterator it);
		bool operator!=(ConstIterator it);

		// @brief イテレータが参照するリストの参照を取得します
		const DoublyLinkedList& GetList();

		bool IsDummy();

	protected:
		Node* pNode = nullptr;
		DoublyLinkedList* pList = nullptr;
	private:
		
	};

	// @brief 双方向リストのコンストイテレータ
	// @brief *演算子でイテレータが示すデータにアクセスできる
	class Iterator :public ConstIterator {
	public:
		Iterator();
		Iterator(DoublyLinkedList* _pList, Node* _pNode);
		
		// @brief 末尾方向に指定した数だけ移動したイテレータを返します
		Iterator operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したイテレータを返します
		Iterator operator-(int n);

		// @brief イテレータが示す要素を取得します
		ResultData& operator*();
		// @brief イテレータが示すコンスト要素を取得します
		ResultData* operator->();//何故かポインタを返さないといけない

	private:
		
	};

	// @brief コンストラクタ
	DoublyLinkedList();
	// @brief デストラクタ
	~DoublyLinkedList();

	// @brief 要素数を取得します
	unsigned int GetSize()const;

	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	bool AddNode(ConstIterator& iterator);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	bool AddNode(Iterator& iterator);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	// @param[in] 追加するノードの数
	bool AddNode(ConstIterator& iterator, int addNum);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	// @param[in] 追加するノードの数
	bool AddNode(Iterator& iterator, int addNum);

	// @brief イテレータが示す位置の要素を削除します
	// @param[in,out] 削除位置のイテレータ
	bool DeleteNode(ConstIterator& iterator);

	// @brief 先頭のイテレータを取得
	Iterator GetBegin();

	// @brief 先頭のコンストイテレータを取得
	ConstIterator GetConstBegin()const;

	// @brief 末尾のイテレータを取得
	Iterator GetEnd();

	// @brief 末尾のコンストイテレータを取得
	ConstIterator GetConstEnd()const;

	// @brief 先頭要素へのポインタを取得
	//Node* GetNode();

private:
	
	// @brief 末尾を示すダミー要素　データは格納されない
	Node dummy;
	// @brief 先頭要素へのポインタ
	Node* pTop = &dummy;

	// @brief 要素の数
	unsigned int size = 0;
};