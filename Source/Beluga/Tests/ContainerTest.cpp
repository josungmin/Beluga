#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	{
		TArray<int32> arr;
		
		// �迭 ���� �� �׸� �߰�
		arr.Add(30);

		// [] �����ڸ� ���� �迭 ����
		TestEqual("Array[0] != 30", arr[0], 30);
	}

	{
		TArray<int32> arr;

		// �迭�� ũ�⸦ �����ϰ� �־��� ��ҷ� ä���.
		arr.Init(10, 5);

		TestEqual("Element in array not init to 10", arr[0], 10);
	}

	{
		TArray<int32> arr1;
		arr1.Add(30);

		TArray<int32> arr2;
		arr2.Add(10);

		// ������ �迭�� �� �迭�� �߰�
		arr1.Append(arr2);

		TestEqual("arr[1] != 10", arr1[1], 10);
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMapTest, "Beluga.Map", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMapTest::RunTest(const FString& Parameters)
{
	{
		TMap<int32, FString> map;

		// map�� ��� �߰�
		map.Add(1, TEXT("Banana"));

		TestEqual("map[1] != Banana", map[1], "Banana");
	}

	{
		TMap<int32, FString> map;

		map.Add(1, TEXT("Banana"));
		map.Add(3, TEXT("Melon"));
		map.Add(7, TEXT("Orange"));
		map.Add(777, TEXT("Kiwi"));

		// map�� ũ�� ��ȯ
		TestEqual("map's size not 4", map.Num(), 4);
	}

	{
		TMap<int32, FString> map;

		map.Add(1, TEXT("Banana"));
		map.Add(3, TEXT("Melon"));
		map.Add(7, TEXT("Orange"));
		map.Add(777, TEXT("Kiwi"));

		// map�� ��� ����
		map[777] = TEXT("Pear");

		TestEqual("map[777] not Pear", map[777], TEXT("Pear"));
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaSetTest, "Beluga.Set", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaSetTest::RunTest(const FString& Parameters)
{
	{
		TSet<FString> set;

		// set�� ��� �߰�
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// Set�� ũ�� ��ȯ
		TestEqual("set's size not 3", set.Num(), 3);
	}

	{
		TSet<FString> set;

		// set�� ��� �߰�
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// set�� ��� ����
		set.Remove(TEXT("Banana"));

		// Set�� ũ�� ��ȯ
		TestEqual("set's size not 2", set.Num(), 2);
	}

	{
		TSet<FString> set;

		// set�� ��� �߰�
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// �ش� ��Ұ� Set�� ����Ǿ� �ִ��� �Ǻ�
		TestTrue("Orange not have", set.Contains(TEXT("Orange")));
	}

	return true;
}