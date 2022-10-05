/**********************************************************************************//**
    @file           List_Test.cpp
    @brief          GoogleTest自動テストコードの書き方サンプル                    
    Copyright &copy FromSoftware, Inc.
*//***********************************************************************************/


// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include "gtest/gtest.h"

// テストプロジェクトのヘッダファイル
#include "../課題１_双方向リスト/DoublyLinkedList.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{

		//=================================== データ数の取得 ===================================
		
		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty){
			DoublyLinkedList list;
			EXPECT_EQ(0,list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			ASSERT_TRUE(list.AddNode(it, 1));
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-2　自動テストを行いません\n　
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
// 			DoublyLinkedList list;
// 			DoublyLinkedList::Iterator it = list.GetEnd();
// 			ASSERT_FALSE(list.Insert(it, 1));
// 			EXPECT_EQ(0, list.GetCount());

		}

		/**********************************************************************************//**
			@brief		データの挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.AddNode(it, 1));
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		データの挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		{
 			DoublyLinkedList list;
 			DoublyLinkedList::Iterator it = list.GetEnd();
			it++;//末尾の次のイテレータ
 			ASSERT_FALSE(list.AddNode(it, 1));
 			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		データを削除した際のデータ数の取得テスト
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データを削除した際の戻り値を確認しています。\n
						データ数が１減っていれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it, 1);
 			ASSERT_TRUE(list.DeleteNode(it));
 			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		データの削除に失敗した際のデータ数の取得テスト
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除に失敗した際の戻り値を確認しています。\n
						データ数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDeleteFailed)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it, 1);
			it++;//末尾ダミーのイテレータ
			ASSERT_FALSE(list.DeleteNode(it));
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストが空である場合に削除を行った際のデータ数の取得テスト
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						リストが空である場合に削除を行った際の戻り値を確認しています。\n
						データ数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDeleteWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_FALSE(list.DeleteNode(it));
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		データ数の取得をする関数がconst関数であるかテスト
			@details	ID:リスト-8　自動テストを行いません\n
						データ数の取得機能のテストです。\n
						constのリストから呼び出して、コンパイルエラーとならなければ成功です。\n
		*//***********************************************************************************/


		//=================================== データの挿入 ===================================
		
		/**********************************************************************************//**
			@brief		リストが空である場合に、データを追加した際の挙動テスト
			@details	ID:リスト-9\n
						データ追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushBackWhenEmpty)
		{
			//先頭に追加
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			EXPECT_EQ(true, list.AddNode(it, 1));
			EXPECT_EQ(1, list.GetSize());

			//末尾に追加
			DoublyLinkedList list2;
			it = list2.GetEnd();
			EXPECT_EQ(true, list2.AddNode(it, 1));
			EXPECT_EQ(1, list2.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-10\n
						リスト先頭のデータ追加テストです。\n
						リストに複数の要素がある場合に、先頭に追加した際の挙動を確認しています。\n
						先頭に要素が挿入され、元々先頭だった要素が２番目になっていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushFront)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it, 1);
			std::string str = "元々先頭のデータ";
			it->resultData.name = str;

			//先頭に要素を追加
			EXPECT_EQ(true, list.AddNode(it, 1));

			//要素を確認
			it++;//2番目の要素へ
			EXPECT_EQ(it->resultData.name, str);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-11\n
						リスト末尾のデータ追加テストです。\n
						リストに複数の要素がある場合に、末尾に追加した際の挙動を確認しています。\n
						末尾に要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushBack)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it, 1);
			std::string str = "元々先頭のデータ";
			it->resultData.name = str;

			//末尾にデータを追加
			it = list.GetEnd();
			EXPECT_EQ(true, list.AddNode(it, 1));
			
			//要素を確認
			it--;//1番目の要素へ
			EXPECT_EQ(it->resultData.name, str);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-12\n
						リストのデータ追加テストです。\n
						リストに複数の要素がある場合に、中間位置に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入され、その位置にあった要素が後ろにずれていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushToMiddle)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を2つ用意する
			list.AddNode(it, 2);
			std::string str = "元々先頭のデータ";
			it->resultData.name = str;
			it++;//2つ目の要素へ
			std::string str2 = "元々２番目のデータ";
			it->resultData.name = str2;

			//2番目に要素を追加
			EXPECT_EQ(true, list.AddNode(it, 1));

			//要素を確認
			it--;//1番目の要素へ
			EXPECT_EQ(it->resultData.name, str);
			EXPECT_EQ((it+2)->resultData.name, str2);

		}

		/**********************************************************************************//**
			@brief		ConstIteratorを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-13\n
						リストのデータ追加テストです。\n
						ConstIteratorを渡して要素列の先頭、中央、末尾にデータを追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入され、その位置にあった要素が後ろにずれていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushByConstIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			std::string nameArray[4] = { "0","1","2","3" };
			//要素を1つ用意
			list.AddNode(cit, 1);
			cit->resultData.name = nameArray[2];

			//先頭に要素を追加
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[0];

			//中央に要素を追加
			cit++;
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[1];

			//末尾に要素を追加
			cit = list.GetConstEnd();
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[3];

			//要素を確認　順序通りになっているか
			int size = list.GetSize();
			for (cit = list.GetConstBegin(); cit.GetNum() < size; cit++) {
				EXPECT_EQ(cit->resultData.name, nameArray[cit.GetNum()]);
			}
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-14\n
						リストのデータ追加テストです。\n
						不正なイテレータを渡してデータを追加した際の挙動を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushByImproprietyIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			//リストの参照がないイテレータを渡す
			EXPECT_EQ(false, list.AddNode(it, 1));

			//範囲外のイテレータを渡す
			it = list.GetBegin();
			EXPECT_EQ(false, list.AddNode(it + 2, 1));
			
			//別リストのイテレータを渡す
			DoublyLinkedList otherList;
			EXPECT_EQ(false, list.AddNode(otherList.GetBegin(), 1));

			//要素が追加されていないことを確認
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		非constのメソッドであるか
			@details	ID:リスト-15 自動テストを行いません\n
						リストのデータ追加テストです。\n
						constのリストから呼び出して、コンパイルエラーとなるかを確認しています。\n
		*//***********************************************************************************/
		//TEST(PushTest, PushToMiddle)
		//{
		//
		//}

		
		//=================================== データの削除 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に削除を行った際の挙動テスト
			@details	ID:リスト-16\n
						データ削除テストです。\n
						リストが空である場合にデータを削除した際の挙動を確認しています。\n
						リストが空のままであれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteWhenEmpty)
		{
			//先頭イテレータを渡す
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			EXPECT_EQ(false, list.DeleteNode(it));
			EXPECT_EQ(0, list.GetSize());

			//末尾イテレータを渡す
			DoublyLinkedList list2;
			it = list2.GetEnd();
			EXPECT_EQ(false, list2.DeleteNode(it));
			EXPECT_EQ(0, list2.GetSize());
		}
		
		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-17\n
						リスト先頭のデータ削除テストです。\n
						リストに複数の要素がある場合に、先頭のデータを削除した際の挙動を確認しています。\n
						先頭要素が削除されていれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を２つ用意する
			list.AddNode(it, 2);
			std::string str = "元々先頭のデータ";
			std::string str2 = "元々２番目のデータ";
			it->resultData.name = str;
			(it + 1)->resultData.name = str2;

			//先頭の要素を削除
			EXPECT_EQ(true, list.DeleteNode(it));

			//要素を確認 ２番目だった要素が先頭要素になっているか
			EXPECT_EQ(it->resultData.name, str2);
		}
		
		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-18\n
						リスト末尾のデータ削除テストです。\n
						リストに複数の要素がある場合に、末尾のデータを削除した際の挙動を確認しています。\n
						データが減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it, 1);

			//末尾のデータを削除
			it = list.GetEnd();
			EXPECT_EQ(false, list.DeleteNode(it));

			//要素数を確認
			EXPECT_EQ(1, list.GetSize());
		}
		//TODO 以降のテスト実装
		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-19\n
						リストのデータ削除テストです。\n
						リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡してデータを削除した際の挙動を確認しています。\n
						イテレータの指す位置のデータが削除されていれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteMiddle)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を2つ用意する
			list.AddNode(it, 2);
			std::string str = "元々先頭のデータ";
			it->resultData.name = str;
			it++;//2つ目の要素へ
			std::string str2 = "元々２番目のデータ";
			it->resultData.name = str2;

			//2番目の要素を削除
			EXPECT_EQ(true, list.DeleteNode(it));

			//要素を確認
			it--;//1番目の要素へ
			EXPECT_EQ(it->resultData.name, str);
			EXPECT_EQ((it + 2)->resultData.name, str2);

		}

		/**********************************************************************************//**
			@brief		ConstIteratorを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-13\n
						リストのデータ追加テストです。\n
						ConstIteratorを渡して要素列の先頭、中央、末尾にデータを追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入され、その位置にあった要素が後ろにずれていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushByConstIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			std::string nameArray[4] = { "0","1","2","3" };
			//要素を1つ用意
			list.AddNode(cit, 1);
			cit->resultData.name = nameArray[2];

			//先頭に要素を追加
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[0];

			//中央に要素を追加
			cit++;
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[1];

			//末尾に要素を追加
			cit = list.GetConstEnd();
			EXPECT_EQ(true, list.AddNode(cit, 1));
			cit->resultData.name = nameArray[3];

			//要素を確認　順序通りになっているか
			int size = list.GetSize();
			for (cit = list.GetConstBegin(); cit.GetNum() < size; cit++) {
				EXPECT_EQ(cit->resultData.name, nameArray[cit.GetNum()]);
			}
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡してデータを追加した際の挙動テスト
			@details	ID:リスト-14\n
						リストのデータ追加テストです。\n
						不正なイテレータを渡してデータを追加した際の挙動を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushToMiddle)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			//リストの参照がないイテレータを渡す
			EXPECT_EQ(false, list.AddNode(it, 1));

			//範囲外のイテレータを渡す
			it = list.GetBegin();
			EXPECT_EQ(false, list.AddNode(it + 2, 1));

			//別リストの要素を指すイテレータを渡す
			DoublyLinkedList otherList;
			EXPECT_EQ(false, list.AddNode(otherList.GetBegin(), 1));

			//要素が追加されていないことを確認
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		非constのメソッドであるか
			@details	ID:リスト-15 自動テストを行いません\n
						リストのデータ追加テストです。\n
						constのリストから呼び出して、コンパイルエラーとなるかを確認しています。\n
		*//***********************************************************************************/
		//TEST(PushTest, PushToMiddle)
		//{
		//
		//}
	}

}