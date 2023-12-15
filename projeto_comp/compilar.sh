#!/bin/bash
#!/bin/bash

case "$#" in
    0)
        ./mooshak.sh
        exit 1
        ;;
    1)
        ./mooshak.sh
        input_file="$1"
        output_file="output"

        ./uccompiler < "$input_file" > "${output_file}.ll" || exit 1
        echo "LLVM code gerado sem problemas"

        llc "${output_file}.ll" -o "${output_file}.s" || exit 1
        echo "Assembly gerado corretamente"

        clang "${output_file}.s" -o "${output_file}" || exit 1
        echo -e "Executável gerado corretamente: ./${output_file}\n\n"

        ./"${output_file}" || exit 1
        ;;
    *)
        input_file="$1"
        output_file="output"

        ./uccompiler < "$input_file" > "${output_file}.ll" || exit 1
        echo "LLVM code gerado sem problemas"

        llc "${output_file}.ll" -o "${output_file}.s" || exit 1
        echo "Assembly gerado corretamente"

        clang "${output_file}.s" -o "${output_file}" || exit 1
        echo -e "Executável gerado corretamente: ./${output_file}\n\n"

        ./"${output_file}" || exit 1
        ;;
esac

# Limpar arquivos intermediArios, se desejar
# rm "${output_file}.ll" "${output_file}.s"
