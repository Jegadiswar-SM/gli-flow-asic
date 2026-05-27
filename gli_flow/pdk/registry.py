from typing import Optional

from gli_flow.pdk.base import PDK


_registry: dict[str, type[PDK]] = {}


def register_pdk(name: str, cls: type[PDK]) -> None:
    _registry[name] = cls


def get_pdk(name: str, variant: str = "", **kwargs) -> Optional[PDK]:
    cls = _registry.get(name)
    if cls is None:
        return None
    kw = {"name": name}
    if variant:
        kw["variant"] = variant
    kw.update(kwargs)
    return cls(**kw)


def list_pdks() -> list[str]:
    return list(_registry.keys())


def discover_pdks():
    import gli_flow.pdk.sky130
    import gli_flow.pdk.gf180mcu
