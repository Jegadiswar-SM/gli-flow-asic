from typing import Optional

from gli_flow.pdk.base import PDK


_registry: dict[str, type[PDK]] = {}


class PDKRegistry:
    def __init__(self):
        self._pdks = _registry

    def register(self, name: str, cls: type[PDK]) -> None:
        self._pdks[name] = cls

    def get(self, name: str, variant: str = "", **kwargs) -> Optional[PDK]:
        return get_pdk(name, variant, **kwargs)

    def list(self) -> list[str]:
        return list(self._pdks.keys())

    def discover(self):
        discover_pdks()


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
    import gli_flow.pdk.ihp_sg13g2
