set mpiExeFileName=%1
set logFileName=%2
for %%n in (2,3,4) do (
   echo --------------------------------------------------- >> .\%logFileName%
   for /F "tokens=2" %%i in ('date /t') do set mydate=%%i >> .\%logFileName%
   set mytime=%time% >> .\%logFileName%
   echo Current time is %mydate%:%mytime% >> .\%logFileName%
   echo %%n processors >> .\%logFileName%
   echo --------------------------------------------------- >> .\%logFileName%
   for %%x in (10,100,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000) do (                                                        
      echo Size: %%x  Number of processes:%%n >> .\%logFileName%
      echo %%x | mpiexec -n %%n %mpiExeFileName% >> .\%logFileName%
   )
)