declare
    basic_pay number(38,5);
begin
    basic_pay:='&basic_pay';
    dbms_output.put_line('Salary= ' || (basic_pay+0.5*basic_pay+0.25*basic_pay-0.12*basic_pay));
end;
/
