declare
    y number(4);
    isLeap number(1);
begin
    y:='&year';
    if mod(y,400)=0 then isLeap:=1;
    elsif mod(y,100)=0 then isLeap:=0;
    elsif mod(y,4)=0 then isLeap:=1;
    else isLeap:=0;
    end if;

    if isLeap=1 then dbms_output.put_line(y || ' is Leap Year.');
    else dbms_output.put_line(y || ' is not Leap Year.');
    end if;
end;
/