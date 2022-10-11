#pragma once
#include<string>

// @brief 成績データを格納する構造体
struct ResultData
{
public:
	std::string score;
	std::string name;
};

// @brief 双方向リストのクラス\n
// 別名bi-directional list
class DoublyLinkedList
{
public:
	//前方宣言
	class Iterator;

	// @brief 双方向リストのノード
	// @brief 構造体ResultDataを格納している
	struct Node {
		DoublyLinkedList::Node* pPrevious = nullptr;
		DoublyLinkedList::Node* pNext = nullptr;
		ResultData resultData;
	};

	// @brief 双方向リストのイテレータ\n
	//		  ＊演算子または->演算子でデータにアクセスできます
	class ConstIterator {
		friend DoublyLinkedList;
	public:
		// @brief コンストラクタ
		ConstIterator();
		// @brief コンストラクタ
		// @param[in] const DoublyLinkedList*
		// @param[in] const Node*
		ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode);

		// @brief コピーコンストラクタ
		// @param[in] const ConstIterator&
		ConstIterator(const ConstIterator& obj);

		// @brief デストラクタ
		virtual ~ConstIterator();

		// @brief 次の要素に移動します
		//        次の要素に移動したイテレータを返します
		ConstIterator& operator++();
		// @brief 次の要素に移動します
		//        次の要素に移動していないイテレータを返します
		ConstIterator operator++(int);
		// @brief 前の要素に移動します
		//        前の要素に移動したイテレータを返します
		ConstIterator& operator--();
		// @brief 前の要素します
		//        前の要素に移動していないイテレータを返します
		ConstIterator operator--(int);

		// @brief 末尾方向に指定した数だけ移動したコンストイテレータを返します
		// @param[in] int
		ConstIterator operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したコンストイテレータを返します
		// @param[in] int
		ConstIterator operator-(int n);

		// @brief イテレータが示すコンスト要素の参照を取得します
		const ResultData& operator*()const;
		// @brief イテレータが示すコンスト要素の参照を取得します
		const ResultData* operator->()const;//何故かポインタを返さないといけない
		
		// @brief 示しているノードが同じものか比較します
		// @param[in] ConstIterator&
		bool operator==(const ConstIterator& it)const;
		// @brief 示しているノードが異なるものか比較します
		// @param[in] ConstIterator&
		bool operator!=(const ConstIterator& it)const;

		// @brief 示しているノードが同じものか比較します
		// @param[in] Iterator&
		bool operator==(const Iterator& it)const;
		// @brief 示しているノードが異なるものか比較します
		// @param[in] Iterator&
		bool operator!=(const Iterator& it)const;


	protected:
		Node* pNode = nullptr;
		DoublyLinkedList* pList = nullptr;
	private:
		
	};

	// @brief 双方向リストのコンストイテレータ\n
	//		　＊演算子または->演算子でデータにアクセスできます
	class Iterator :public ConstIterator {
	public:
		// @brief コンストラクタ
		Iterator();
		// @brief コンストラクタ
		// @param[in] 参照するリスト
		// @param[in] 示すノード
		Iterator(DoublyLinkedList* _pList, Node* _pNode);
		
		// @brief コピーコンストラクタ
		// @param[in] コピー元のオブジェクト
		Iterator(const Iterator& obj) = default;

		// @brief デストラクタ
		virtual ~Iterator();

		// @brief 次の要素に移動します
		//        次の要素に移動したイテレータを返します
		Iterator& operator++();
		// @brief 次の要素に移動します
		//        次の要素に移動していないイテレータを返します
		Iterator operator++(int);
		// @brief 前の要素に移動します
		//        前の要素に移動したイテレータを返します
		Iterator& operator--();
		// @brief 前の要素します
		//        前の要素に移動していないイテレータを返します
		Iterator operator--(int);

		// @brief 末尾方向に指定した数だけ移動したイテレータを返します
		// @param[in] int
		Iterator operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したイテレータを返します
		// @param[in] int
		Iterator operator-(int n);

		// @brief 示すノードが同じものか比較します
		//　@param[in] Iterator&
		bool operator==(Iterator& it)const;
		// @brief 示すノードが異なるものか比較します
		//　@param[in] Iterator&
		bool operator!=(Iterator& it)const;

		// @brief 示すノードが同じものか比較します
		//　@param[in] ConstIterator&
		bool operator==(const ConstIterator& it)const;
		// @brief 示すノードが異なるものか比較します
		//　@param[in] ConstIterator&
		bool operator!=(const ConstIterator& it)const;

		// @brief イテレータが示す要素を取得します
		ResultData& operator*();
		// @brief イテレータが示すコンスト要素を取得します
		ResultData* operator->();

	private:
		
	};

	// @brief コンストラクタ
	DoublyLinkedList();

	// @brief コピーコンストラクタ
	DoublyLinkedList(const DoublyLinkedList& obj) = default;

	// @brief デストラクタ
	virtual ~DoublyLinkedList();

	// @brief 要素数を取得します
	unsigned int GetSize()const;

	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	// @param[in] 格納するデータ
	bool Insert(ConstIterator& iterator, const ResultData& data);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	// @param[in] 格納するデータ
	bool Insert(Iterator& iterator, const ResultData& data);

	// @brief イテレータが示す位置の要素を削除します
	// @param[in,out] 削除位置のイテレータ
	bool Delete(ConstIterator& iterator);

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