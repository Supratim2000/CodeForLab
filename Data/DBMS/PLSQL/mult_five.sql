declare
    num number;
    ct number;
begin
    ct:='&range';
    for i in 1..ct loop
        dbms_output.put_line('5 X ' || i || '= ' || 5*i);
    end loop;
end;
/