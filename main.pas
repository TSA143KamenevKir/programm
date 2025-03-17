program zz1; 
function IsSquare(n: integer): boolean;
var 
    i: real;
    
begin
    i := sqrt(n); // Находим квадратный корень из числа
    IsSquare := frac(i) = 0; // Возвращаем True если i целое число
end;

var
    numbers: array[1..10] of integer;
    i, k: integer;

begin
    k := 0;
    
    // Ввод 10 целых положительных чисел
    writeln('Введите 10 целых положительных чисел:');
    for i := 1 to 10 do
    begin
      readln(numbers[i]);
    end;
    
    // Проверка на квадрат каждого числа из наора
    for i := 1 to 10 do
    begin
        if IsSquare(numbers[i]) then
        begin
            k := k + 1;
        end;
    end; 
    
    writeln('Количество квадрaтов в наборе:',k);
end.
