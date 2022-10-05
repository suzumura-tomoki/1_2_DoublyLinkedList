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
	class Iterator {
	public:
		//コンストラクタ
		Iterator();
		Iterator(DoublyLinkedList* l, int n);

		// @brief 次の要素にイテレータを移動します
		void operator--();
		// @brief 前の要素にイテレータを移動します
		void operator++();
		// @brief 末尾方向に指定した数だけ移動したイテレータを返します
		Iterator operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したイテレータを返します
		Iterator operator-(int n);
		// @brief イテレータが示す要素を取得します
		Node& operator*();
		// @brief イテレータが示す要素を取得します
		Node* operator->();//何故かポインタを返さないといけない
		// @brief イテレータを比較します
		bool operator==(Iterator it);
		bool operator!=(Iterator it);

		// @brief イテレータが示す要素番号を取得します
		unsigned int GetNum();
		// @brief イテレータが参照するリストを取得します
		DoublyLinkedList& GetList();

	private:
		unsigned int num = 0;
		DoublyLinkedList* pList = nullptr;
	};

	// @brief 双方向リストのコンストイテレータ
	// @brief *演算子でイテレータが示すデータにアクセスできる
	class ConstIterator :public Iterator {
	public:
		ConstIterator(DoublyLinkedList* l, int n);
		// @brief イテレータが示すコンスト要素を取得します
		const Node operator*();
		// @brief コピーコンストラクタ
		//ConstIterator(const ConstIterator& obj);

	};

	// @brief コンストラクタ
	DoublyLinkedList();
	// @brief デストラクタ
	~DoublyLinkedList();

	// @brief 要素数を取得します
	unsigned int GetSize();

	// @brief イテレータが示す位置に要素を追加します
	// @param[in] 追加位置のイテレータ
	bool AddNode(Iterator iterator);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in] 追加位置のイテレータ
	// @param[in] 追加するノードの数
	bool AddNode(Iterator iterator, int addNum);

	// @brief イテレータが示す位置の要素を削除します
	// @param[in] 削除位置のイテレータ
	bool DeleteNode(Iterator iterator);

	// @brief 先頭のイテレータを取得
	Iterator GetBegin();

	// @brief 先頭のコンストイテレータを取得
	ConstIterator GetConstBegin();

	// @brief 末尾のイテレータを取得
	Iterator GetEnd();

	// @brief 末尾のコンストイテレータを取得
	ConstIterator GetConstEnd();

	// @brief ノードへのポインタを取得
	Node* GetNode(Iterator it);
	// @brief ノードへのポインタを取得 始点ダミーの次要素を０として指定番号の要素のポインタを返す
	Node* GetNode(unsigned int num);

private:
	// @brief 先頭を示すダミー要素　データは格納されない
	Node beginDummy;
	// @brief 末尾を示すダミー要素　データは格納されない
	Node endDummy;
	// @brief 先頭ポインタ
	//Node* pBegin = nullptr;
	// @brief 末尾ポインタ
	//Node* pEnd = nullptr;

	// @brief 要素の数
	unsigned int size = 0;
};