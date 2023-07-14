#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	{
		TArray<int32> arr;
		
		// 배열 끝에 새 항목 추가
		arr.Add(30);

		// [] 연산자를 통한 배열 접근
		TestEqual("Array[0] != 30", arr[0], 30);
	}

	{
		TArray<int32> arr;

		// 배열의 크기를 설정하고 주어진 요소로 채운다.
		arr.Init(10, 5);

		TestEqual("Element in array not init to 10", arr[0], 10);
	}

	{
		TArray<int32> arr1;
		arr1.Add(30);

		TArray<int32> arr2;
		arr2.Add(10);

		// 지정된 배열을 이 배열에 추가
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

		// map에 요소 추가
		map.Add(1, TEXT("Banana"));

		TestEqual("map[1] != Banana", map[1], "Banana");
	}

	{
		TMap<int32, FString> map;

		map.Add(1, TEXT("Banana"));
		map.Add(3, TEXT("Melon"));
		map.Add(7, TEXT("Orange"));
		map.Add(777, TEXT("Kiwi"));

		// map의 크기 반환
		TestEqual("map's size not 4", map.Num(), 4);
	}

	{
		TMap<int32, FString> map;

		map.Add(1, TEXT("Banana"));
		map.Add(3, TEXT("Melon"));
		map.Add(7, TEXT("Orange"));
		map.Add(777, TEXT("Kiwi"));

		// map의 요소 수정
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

		// set에 요소 추가
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// Set의 크기 반환
		TestEqual("set's size not 3", set.Num(), 3);
	}

	{
		TSet<FString> set;

		// set에 요소 추가
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// set에 요소 제거
		set.Remove(TEXT("Banana"));

		// Set의 크기 반환
		TestEqual("set's size not 2", set.Num(), 2);
	}

	{
		TSet<FString> set;

		// set에 요소 추가
		set.Add(TEXT("Banana"));
		set.Add(TEXT("Kiwi"));
		set.Add(TEXT("Orange"));

		// 해당 요소가 Set의 저장되어 있는지 판별
		TestTrue("Orange not have", set.Contains(TEXT("Orange")));
	}

	return true;
}