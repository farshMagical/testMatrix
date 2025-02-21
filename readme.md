
  #   Транспонирование матриц
  Несколько реализаций асинхронных воркеров для транспонирования матрицы. 
  Для тестирования использован gtest.
  
  ##  Требования к реализации
  - Полученный класс не должен транспонировать матрицу внутри фукнции
AsyncProcess.
  - Создавать отдельный поток на каждый вызов AsyncProcess тоже нельзя.
  - Вызов AsyncProcess не должен ждать завершения процесса транспонирования

  ## Установка и запуск
  $ git clone ...  
  $ cd testMatrix  
  $ mkdir build  
  $ cd build  
  $ cmake ..  
  $ make  
  $ ./matrixTest
  
  ## Работа программы  
  Происходит запуск тестов. Тестируются четыре набора:  
  - Тестирование методов транспонировая класса Matrix. 
  Реализованы два метода - транспонирование и транспонирование в два потока (через async).
  - Тестирование воркера sThread, запускающего через std::async выполнение того или 
  иного метода транспонирования. (Нарушает требования к реализации. Async вызывает создание потока)
  - Тестирование воркера mThread, использующего пул из 3 потоков и потокобезопасную очередь для хранения
  команд на транспонирование.
  - Тестирования времени исполнения

  ## Вывод части работы программы с тестированием времени исполнения

[----------] 6 tests from timeTest  
[ RUN      ] timeTest.Matrix_Transpose  
[       OK ] timeTest.Matrix_Transpose (5145 ms)  **транспонирование**  
[ RUN      ] timeTest.Matrix_Parallel_Transpose  
[       OK ] timeTest.Matrix_Parallel_Transpose (3645 ms)  **транспонирование в 2 потока**    
[ RUN      ] timeTest.asyn_Transpose  
[       OK ] timeTest.asyn_Transpose (3400 ms) **Транспонирование через async()**  
[ RUN      ] timeTest.asyn_withBoundedPool_Transpose  
[       OK ] timeTest.asyn_withBoundedPool_Transpose (2394 ms) **Транспонирование через пул**    
[ RUN      ] timeTest.asyn_Parallel_Transpose  
[       OK ] timeTest.asyn_Parallel_Transpose (3292 ms)  **Транспонирование в 2потока через async()**  
[ RUN      ] timeTest.asyn_withBoundedPool_Parallel_Transpose  
[       OK ] timeTest.asyn_withBoundedPool_Parallel_Transpose (2576 ms) **Транспонирование в 2 потока через пул**    
[----------] 6 tests from timeTest (20454 ms total)  
  
[----------] Global test environment tear-down  
[==========] 12 tests from 4 test suites ran. (20460 ms total)  
[  PASSED  ] 12 tests.  


      
  ### Обратная связь 
  tg: @proshch ✨  
  proshchenko78@yandex.ru🔥
  
