﻿Проект №2: Стековая машина
==========================

## Структура проекта

Проект структурирован в соответствии с принятыми стандартами и содержит следующие каталоги верхнего уровня:

* `/docs` — документация: задание;
* `/src` — исходные платформо-мало-или-почти-независимые коды;
* `/tests` — тесты
* `readme.md` — ридмишка с комментариями к содержимому текущего каталога в формате Markdown. Чтобы просмотреть локальную версию файла с красивым форматированием, можно открыть в Firefox с установленным каким-то там плагином.


### Описание задания
[docs/document.pdf](docs/document.pdf)

### Результаты

[Ссылка на ведомость](https://eduhseru-my.sharepoint.com/:x:/g/personal/arodriges_edu_hse_ru/EYTan9DfmEpFpzLy3dGhd38BE8GgFjSTKyLPOoqHQhPcDQ?e=vtIqrs)

### Как указать свой вариант
В файле [stack_machine.h](src/stack_machine.h) в самом верху у вас есть 10 директив препроцессора `define`. 
Вы раскомментируете только те дефайны, которые соответствуют операторам (см. раздел 3.3 [задания](docs/document.pdf) ) индивидуального варианта. 
При этом у вас автоматически "разблокируются" встроенные тесты и нужные классы.

Файл с распределением вариантов по фамилиям: [docs/ind-vars.pdf](docs/ind-vars.pdf)
### ВАЖНО!!!
Если вы этого не сделаете, то тесты и нужные классы работать не будут!!!  
Если вы отправите задание, в котором раскомментировано меньше трёх define-ов 
(не считая `PLUS_OP`), то это будет проверено специальным тестом. Больше можно.

# Дедлайн:
## 20.10.19 23:59
Коммиты после этого времени будут игнорироваться.

[comment]: <> (было так: [lp_doxydoc]: docs/doxydoc/readme.md, но путь надо давать относительно каталога с Doxyfile!)
[lp_doxydoc]: readme.md
