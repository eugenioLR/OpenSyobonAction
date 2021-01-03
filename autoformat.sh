ext=".f";
for i in $(ls *.cpp);
do
  clang-format $i > "$i$ext";
done;

for i in $(ls *.cpp.f);
do
    mv $i $(echo "$i" | cut -d "." -f 1,2
    );
done;

ext=".f";
for i in $(ls *.h);
do
  clang-format $i > "$i$ext";
done;

for i in $(ls *.h.f);
do
    mv $i $(echo "$i" | cut -d "." -f 1,2
    );
done;
