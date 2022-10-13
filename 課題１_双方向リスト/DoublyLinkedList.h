#pragma once
#include<string>

/**
 * @brief 成績データを格納する構造体
 */
struct ResultData
{
public:
	std::string score;
	std::string name;
};

/**
 * @brief 双方向リストのクラス\n
 *		  別名bi-directional list
 */
class DoublyLinkedList
{
public:

	/**
	 * @brief 双方向リストのノード\n
	 *		 構造体ResultDataを格納している
	 */
	struct Node {
		DoublyLinkedList::Node* pPrevious = nullptr;
		DoublyLinkedList::Node* pNext = nullptr;
		ResultData resultData;
	};

	/**
	 * @brief 双方向リストのコンストイテレータ\n
	 *		  ＊演算子または->演算子でデータにアクセスできます
	 */
	class ConstIterator {
		friend DoublyLinkedList;
	public:
		/**
		 * @brief コンストラクタ
		 */
		ConstIterator();
		/**
		 * @brief コンストラクタ
		 * @param[in] const DoublyLinkedList* 参照するリストノードへのポインタ
		 * @param[in] const Node* コンストイテレータが示すノードへのポインタ
		 */
		ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode);

		/**
		 * @brief コピーコンストラクタ
		 * @param[in] const ConstIterator& コピー元のオブジェクト
		 */
		ConstIterator(const ConstIterator& obj);

		/**
		 * @brief デストラクタ
		 */
		virtual ~ConstIterator();

		/**
		 * @brief 次の要素に移動します
		 * @return 移動したコンストイテレータ
		 */
		ConstIterator& operator++();
		/**
		 * @brief 次の要素に移動します
		 * @return 移動していないコンストイテレータ
		 */
		ConstIterator operator++(int);

		/**
		 * @brief 前の要素に移動します
		 * @return 移動したコンストイテレータ
		 */
		ConstIterator& operator--();
		/**
		 * @brief 前の要素に移動します
		 * @return 移動していないコンストイテレータ
		 */
		ConstIterator operator--(int);

		/**
		 * @brief 末尾方向に指定した数だけ移動したコンストイテレータを返します
		 * @param[in] int 移動回数
		 * @return 移動したコンストイテレータ
		 */
		ConstIterator operator+(int n)const;
		/**
		 * @brief 先頭方向に指定した数だけ移動したコンストイテレータを返します
		 * @param[in] int 移動回数
		 * @return 移動したコンストイテレータ
		 */
		ConstIterator operator-(int n)const;

		/**
		 * @brief イテレータの示すノードが同じものか比較します
		 * @param[in] ConstIterator& 比較対象
		 * @return bool 同じノードを指していればtrue、それ以外ならfalse
		 */
		bool operator==(const ConstIterator& it)const;

		/**
		 * @brief イテレータの示すノードが異なるものか比較します
		 * @param[in] ConstIterator& 比較対象
		 * @return bool 異なるノードを指していればtrue、それ以外ならfalse
		 */
		bool operator!=(const ConstIterator& it)const;

		/**
		 * @brief コンストイテレータが示す要素のコンスト参照を取得します
		 * @return const ResultData& イテレータが示す要素のコンスト参照
		 */
		const ResultData& operator*()const;
		/**
		 * @brief コンストイテレータが示すコンスト要素を取得します\n
		 *		  暗黙的に戻り値の持つ->が呼ばれます
		 * @return const ResultData* コンストイテレータが示すコンスト要素へのポインタ
		 */
		const ResultData* operator->()const;


	protected:
		/**
		 * @brief このイテレータが示すノードへのポインタ
		 */
		Node* pNode = nullptr;
		/**
		 * @brief このイテレータが参照しているリストへのポインタ
		 */
		DoublyLinkedList* pList = nullptr;
	private:

	};


	/**
	* @brief 双方向リストのイテレータ\n
	*		 継承：コンストイテレータ\n
	*		 ＊演算子または->演算子でデータにアクセスできます
	*/
	class Iterator :public ConstIterator {
	public:
		/**
		 * @brief コンストラクタ
		 */
		Iterator();
		/**
		 * @brief コンストラクタ
		 * @param[in] 参照するリスト
		 * @param[in] 示すノード
		 */
		Iterator(const DoublyLinkedList* _pList, const Node* _pNode);

		/**
		 * @brief コピーコンストラクタ default
		 * @param[in] コピー元のオブジェクト
		 */
		Iterator(const Iterator& obj) = default;

		/**
		 * @brief デストラクタ
		 */
		virtual ~Iterator();

		/**
		 * @brief 次の要素に移動します
		 * @return 移動したイテレータ
		 */
		Iterator& operator++();
		/**
		 * @brief 次の要素に移動します
		 * @return 移動していないイテレータ
		 */
		Iterator operator++(int);
		/**
		 * @brief 前の要素に移動します
		 * @return 移動したイテレータ
		 */
		Iterator& operator--();
		/**
		 * @brief 前の要素に移動します
		 * @return 移動していないイテレータ
		 */
		Iterator operator--(int);

		/**
		 * @brief 末尾方向に指定した数だけ移動したイテレータを返します
		 * @param[in] int 移動回数
		 * @return 移動したイテレータ
		 */
		Iterator operator+(int n);
		/**
		 * @brief 先頭方向に指定した数だけ移動したイテレータを返します
		 * @param[in] int 移動回数
		 * @return 移動したイテレータ
		 */
		Iterator operator-(int n);

		/**
		 * @brief イテレータが示す要素の参照を取得します
		 * @return ResultData& イテレータが示す要素の参照
		 */
		ResultData& operator*();
		/**
		 * @brief イテレータが示す要素を取得します\n
		 *		  暗黙的に戻り値の持つ->が呼ばれます
		 * @return ResultData* イテレータが示す要素へのポインタ
		 */
		ResultData* operator->();


	private:

	};

	/**
	 * @brief コンストラクタ
	 */
	DoublyLinkedList();

	/**
	 * @brief コピーコンストラクタ default
	 */
	DoublyLinkedList(const DoublyLinkedList& obj) = default;

	/**
	 * @brief デストラクタ\n 
	 * 確保したノードを全て解放する
	 */
	virtual ~DoublyLinkedList();

	/**
	 * @brief 要素数を取得します
	 * @return unsigned int 要素数
	 */
	unsigned int GetSize()const;

	/**
	 * @brief イテレータが示す要素の前に要素を挿入します\n
	 *		  追加した要素にイテレータを移動させます
	 * @param[in,out] 挿入位置のイテレータ、挿入した要素に移動します 
	 * @param[in]	  格納するデータ 
	 * @return bool true:挿入に成功\n
	 *				false:挿入に失敗
	 */
	bool Insert(ConstIterator& iterator, const ResultData& data);

	/**
	 * @brief イテレータが示す要素を削除します\n
	 *		  削除した要素の次の要素にイテレータを移動させます
	 * @param[in,out] 削除する要素のイテレータ
	 * @return bool true:削除に成功\n
	 *				false:削除に失敗
	 */
	bool Delete(ConstIterator& iterator);

	/**
	 * @brief 先頭のイテレータを取得
	 * @return 先頭のイテレータ
	 */
	Iterator GetBegin();

	/**
	 * @brief 先頭のコンストイテレータを取得
	 * @return 先頭のコンストイテレータ
	 */
	ConstIterator GetConstBegin()const;

	/**
	 * @brief 末尾のイテレータを取得
	 * @return 末尾のイテレータ
	 */
	Iterator GetEnd();

	/**
	 * @brief 末尾のコンストイテレータを取得
	 * @return 末尾のコンストイテレータ
	 */
	ConstIterator GetConstEnd()const;

private:

	/**
	 * @brief 末尾を示すダミー要素　データは格納されない
	 */
	Node dummy;

	/**
	 * @brief 先頭要素へのポインタ\n
	 *		  循環しない
	 */
	Node* pTop;

	/**
	 * @brief 要素数
	 */
	unsigned int size;
};