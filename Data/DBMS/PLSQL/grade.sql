declare
    m number(5,2);
    g varchar2(1);
begin
    m:='&marks';
    if m>=90 and m<=100 then g:='0';
    elsif m>=80 and m<=89 then g:='E';
    elsif m>=70 and m<=79 then g:='A';
    elsif m>60 and m<=69 then g:='B';
    else g:='F';
    end if;
    dbms_output.put_line('Grade is '|| g);
end;
/